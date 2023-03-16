#include "../hpp/EntityManager.hpp"

EntityManager::EntityManager(unsigned int width = 800, unsigned int height = 800, std::string name = "Bowling Engine", bool isServ = false)
{
    _wSize = {width, height};
    _isServ = isServ;
    if (!isServ) {
        _window.create(sf::VideoMode(width, height), name);
        _window.setFramerateLimit(60);
    }
    //_music.openFromFile("assets/sprites/Music.ogg");

    _systemsList.emplace_back(std::make_unique<EventSystem>(getComponentsList(), *this, _window));
    _systemsList.emplace_back(std::make_unique<PhysicsSystem>(getComponentsList(), *this));
    _systemsList.emplace_back(std::make_unique<DisplaySystem>(getComponentsList(), *this, _window));
    _systemsList.emplace_back(std::make_unique<ShootSystem>(getComponentsList(), *this));
    _systemsList.emplace_back(std::make_unique<AnimSystem>(getComponentsList(), *this));
    _systemsList.emplace_back(std::make_unique<ColisionSystem>(getComponentsList(), *this));
}

void EntityManager::update()
{
    sf::Time elapsed = _clock.restart();
    for (std::size_t i = 0; i < _systemsList.size(); i++)
        _systemsList[i]->update(elapsed);

    //if (!_isMusicPlaying) {
    //    _music.play();
    //    _isMusicPlaying = true;
    //}
}

std::unique_ptr<Entity>& EntityManager::addEntity()
{
    _entitiesList[_entityId] = std::make_unique<Entity>(*this, _entityId);
    _entityId++;
    return _entitiesList[_entityId - 1];
}

void EntityManager::removeEntity(std::unique_ptr<Entity>& entity)
{
    std::vector<std::shared_ptr<IComponent>>& siblings = entity->getSiblings();

    // Erase les références des components dans la list de components
    for (std::size_t i = _componentsList.size() - 1; i != 0; i--) {
        for (std::size_t j = 0; j < siblings.size(); j++) {
            if (siblings[j] == _componentsList[i]) {
                _componentsList.erase(_componentsList.begin() + i);
                break;
            }
        }
    }

    // Erase les références des components dans les siblings
    for (std::size_t i = 0; i < siblings.size(); i++) {
        std::vector<std::shared_ptr<IComponent>>& siblings2 = siblings[i]->getSiblings();
        while (siblings2.empty() == false)
            siblings2.erase(siblings2.begin());
    }

    // Erase l'entity
    _entitiesList.erase(entity->getId());
}

void EntityManager::removeEntityFromComp(std::shared_ptr<IComponent>& comp)
{
    bool remove = false;
    for (const auto& elem : _entitiesList) {
        std::vector<std::shared_ptr<IComponent>> siblings = elem.second->getSiblings();
        for (std::size_t i = 0; i < siblings.size(); i++) {
            if (comp == siblings[i]) {
                removeEntity(_entitiesList[elem.first]);
                remove = true;
            }
        }
        if (remove)
            break;
    }
}