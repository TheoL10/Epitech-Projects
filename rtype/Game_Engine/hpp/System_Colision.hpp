#pragma once

#include "EntityManager.hpp"
#include "System.hpp"
#include "Comp_Colision.hpp"
#include "Comp_TextSprite.hpp"
#include "Comp_Event.hpp"
#include "Comp_Scene.hpp"

#include <tuple>

class ColisionSystem : public System {
    public:
        ColisionSystem(std::vector<std::shared_ptr<IComponent>>& list, EntityManager& admin) : _componentsList(list), _admin(admin) {}

        void update(sf::Time elapsed);
        bool checkColision(std::size_t id, int idScene, EntityType type);
        void doColision();
    private:
        std::vector<std::shared_ptr<IComponent>>& _componentsList;
        EntityManager& _admin;
        std::vector<std::shared_ptr<IComponent>> _deleteEntities;


        std::vector<std::tuple<std::shared_ptr<IComponent>, std::shared_ptr<IComponent>>> _colisions;
        //std::vector<std::shared_ptr<IComponent>> _toDelete1;
        //std::vector<std::shared_ptr<IComponent>> _toDelete2;
};