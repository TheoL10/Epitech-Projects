#pragma once

#include "EntityManager.hpp"
#include "System.hpp"
#include "Comp_Position.hpp"
#include "Comp_Gravity.hpp"
#include "Comp_Velocity.hpp"
#include "Comp_Move.hpp"
#include "Comp_Vector.hpp"
#include "Comp_Event.hpp"
#include "Comp_Scene.hpp"

#include <map>

class PhysicsSystem : public System {
    public:
        PhysicsSystem(std::vector<std::shared_ptr<IComponent>>& list, EntityManager& admin) : _componentsList(list), _admin(admin) {}

        void update(sf::Time elapsed);
    private:
        std::vector<std::shared_ptr<IComponent>>& _componentsList;
        EntityManager& _admin;
        std::map<std::shared_ptr<IComponent>, int> _onLeft;
        std::map<std::shared_ptr<IComponent>, int> _onRight;
};