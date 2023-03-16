#include "../hpp/System_Colision.hpp"

void ColisionSystem::update(sf::Time elapsed)
{
    (void)elapsed;
    for (std::size_t i = 0; i < _componentsList.size(); i++) {
        if (compareType<ColisionComponent>(_componentsList[i])) {
            std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[i]->getSiblings();
            int idSibScene = findInSiblings<SceneComponent>(siblings);
            if (idSibScene == -1)
                checkColision(i, -1, _componentsList[i]->getEntityType());
            else if (siblings[idSibScene]->getIdScene() == _admin.getCurrScene())
                checkColision(i, siblings[idSibScene]->getIdScene(), _componentsList[i]->getEntityType());
        }
    }
    doColision();
}

bool ColisionSystem::checkColision(std::size_t id, int idScene, EntityType type)
{
    for (std::size_t i = 0; i < _componentsList.size(); i++) {
        if (compareType<ColisionComponent>(_componentsList[i])) {
            if ( _componentsList[i]->getEntityType() != type) {
                std::vector<std::shared_ptr<IComponent>> siblings2 = _componentsList[i]->getSiblings();
                int idSibScene2 = findInSiblings<SceneComponent>(siblings2);
                int idScene2 = idSibScene2 == -1 ? -1 : _componentsList[idSibScene2]->getIdScene();

                if (id != i && (idScene == -1 || idScene2 == -1 || idScene == idScene2)) {
                    std::vector<std::shared_ptr<IComponent>> siblings1 = _componentsList[id]->getSiblings();

                    int idText1 = findInSiblings<TextureSpriteComp>(siblings1);
                    int idText2 = findInSiblings<TextureSpriteComp>(siblings2);

                    sf::FloatRect boundingBox1 = siblings1[idText1]->getSprite().getGlobalBounds();
                    sf::FloatRect boundingBox2 = siblings2[idText2]->getSprite().getGlobalBounds();

                    // Bug when the laserBeam is at 0 0 for no reason
                    if ((boundingBox2.left == 0 && boundingBox2.top == 0) || (boundingBox1.left == 0 && boundingBox1.top == 0))
                        break;

                    if (boundingBox1.intersects(boundingBox2)) {
                        _colisions.emplace_back(std::make_tuple(_componentsList[i], _componentsList[id]));
                    }
                }
            }
        }
    }
    return false;
}

void ColisionSystem::doColision()
{
    for (std::size_t i = 0; i < _colisions.size(); i++) {
        std::vector<std::shared_ptr<IComponent>> siblings1 = std::get<0>(_colisions[i])->getSiblings();

        int idEvent1 = findInSiblings<EventComponent>(siblings1);

        if (idEvent1 != -1)
            siblings1[idEvent1]->onColision(std::get<0>(_colisions[i]), std::get<1>(_colisions[i]), std::get<1>(_colisions[i])->getEntityType());
    }
    _colisions.clear();
}