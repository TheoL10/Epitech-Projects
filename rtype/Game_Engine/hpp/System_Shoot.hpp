#pragma once

#include "EntityManager.hpp"
#include "System.hpp"
#include "Comp_Shoot.hpp"
#include "Comp_TextSprite.hpp"
#include "Comp_Position.hpp"
#include "Comp_Vector.hpp"
#include "Comp_Velocity.hpp"
#include "Comp_Colision.hpp"
#include "Comp_Sound.hpp"
#include "EventShoot.hpp"

class EntityManager;

class ShootSystem : public System {
    public:
        ShootSystem(std::vector<std::shared_ptr<IComponent>>& list, EntityManager& admin) : _componentsList(list), _admin(admin) {}

        void update(sf::Time elapsed);
        void createShoot(int id, sf::Vector2f vec, EntityType type);
        sf::Vector2f getAutoShootVec(int id);

    private:
        std::vector<std::shared_ptr<IComponent>>& _componentsList;
        EntityManager& _admin;
};