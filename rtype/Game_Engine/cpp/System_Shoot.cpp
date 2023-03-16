#include "../hpp/System_Shoot.hpp"

// Iterate on components
void ShootSystem::update(sf::Time elapsed)
{
    (void)elapsed;
    for (std::size_t i = 0; i < _componentsList.size(); i++) {
        if (compareType<ShootComponent>(_componentsList[i])) {
            std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[i]->getSiblings();
            int idScene = findInSiblings<SceneComponent>(siblings);
            if (idScene == -1 || siblings[idScene]->getIdScene() == _admin.getCurrScene()) {
                // Check time between the last shot
                _componentsList[i]->setShootTime();
                float shootPerSec = _componentsList[i]->getShootPerSecond();
                sf::Time currTime = _componentsList[i]->getTimeBeforeLastShoot();
                sf::Time shootTime = sf::seconds(1.0f / shootPerSec);

                int idPos = findInSiblings<PositionComponent>(siblings);
                bool isInWindow = true;
                if (idPos != -1) {
                    if (siblings[idPos]->getX() < _admin.getSizeWindow().x && siblings[idPos]->getX() > 0) {
                        if (siblings[idPos]->getY() < _admin.getSizeWindow().y && siblings[idPos]->getY() > 0) {
                            isInWindow = true;
                        } else
                            isInWindow = false;
                    } else
                        isInWindow = false;
                }

                // Compare time before last shot and the frequency of the ship
                // If player stay on shot key it will only shoot X shot per second
                
                if (isInWindow && _componentsList[i]->getAutoShoot() && (currTime > shootTime))
                    createShoot(i, getAutoShootVec(i), ENEMY);
                if (!_componentsList[i]->getAutoShoot() && _componentsList[i]->getWantToShoot() && (currTime > shootTime))
                    createShoot(i, {1, 0}, ALLY);
                _componentsList[i]->setWantToShoot(false);
            }
        }
    }
}

// Create a new entity with shot caracteristics
void ShootSystem::createShoot(int id, sf::Vector2f vec, EntityType type)
{
    //std::cout << "ALO" << std::endl;
    // Reset shootTime to wait for the next shot
    _componentsList[id]->resetShootTime();

    // Query other component infos
    std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[id]->getSiblings();
    int idPos = findInSiblings<PositionComponent>(siblings);
    int textPos = findInSiblings<TextureSpriteComp>(siblings);
    int idScene = findInSiblings<SceneComponent>(siblings);
    int idSound = findInSiblings<SoundComponent>(siblings);

    //std::cout << "VEC: " << vec.x << " " << vec.y << std::endl;

    if (idSound != -1)
        siblings[idSound]->playSoundShoot();

    // Create a new entity with components
    EntityR shoot = _admin.addEntity();

    std::shared_ptr<IComponent> textShoot = shoot->addComponent<TextureSpriteComp>(_componentsList[id]->getPath());
    textShoot->setScale(_componentsList[id]->getSize(),_componentsList[id]->getSize());

    // Place the center of the shot at the center of the ship
    sf::Vector2f sizeShip = siblings[textPos]->getRealSize();
    sf::Vector2f sizeShot = textShoot->getRealSize();
    float centerYShip = siblings[idPos]->getY() + (sizeShip.y / 2) - (sizeShot.y / 2);
    ComponentR posComp = shoot->addComponent<PositionComponent>(siblings[idPos]->getX() + sizeShip.x, centerYShip);

    shoot->addComponent<VectorComponent>(vec.x, vec.y);
    shoot->addComponent<VelocityComponent>(10, 10);
    shoot->addComponent<ColisionComponent>(type);
    shoot->addComponent<EventShoot>();
    if (idScene != -1)
        shoot->addComponent<SceneComponent>(siblings[idScene]->getIdScene());
    
    if (type == ENEMY) {
        ComponentR animComp = shoot->addComponent<AnimComponent>();
        animComp->setIdleAnim({0, 0, 8, 8}, 8, 10.0f, true);
        textShoot->setTextureRect({0, 0, 8, 8});
        textShoot->setScale(2, 2);
        posComp->setPos(siblings[idPos]->getX(), centerYShip);
    }
}

sf::Vector2f ShootSystem::getAutoShootVec(int id)
{
    sf::Vector2f res = {_componentsList[id]->getVecAutoShoot().x, _componentsList[id]->getVecAutoShoot().y};

    if (res.x == 0 && res.y == 0) {
        for (std::size_t i = 0; i < _componentsList.size(); i++) {
            if (compareType<ColisionComponent>(_componentsList[i])) {
                if (_componentsList[i]->getEntityType() == ALLY) {
                    std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[i]->getSiblings();
                    int idPos = findInSiblings<PositionComponent>(siblings);
                    if (idPos != -1) {
                        std::vector<std::shared_ptr<IComponent>> siblings2 = _componentsList[id]->getSiblings();
                        int idPos2 = findInSiblings<PositionComponent>(siblings2);

                        return {siblings[idPos]->getX() - siblings2[idPos2]->getX(), siblings[idPos]->getY() - siblings2[idPos2]->getY()};
                    }
                }
            }
        }
    }
    return res;
}