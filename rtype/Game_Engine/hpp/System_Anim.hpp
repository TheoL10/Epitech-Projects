#pragma once

#include "EntityManager.hpp"
#include "System.hpp"
#include "Comp_Anim.hpp"
#include "Comp_TextSprite.hpp"
#include "Comp_Scene.hpp"

class AnimSystem : public System {
    public:
        AnimSystem(std::vector<std::shared_ptr<IComponent>>& list, EntityManager& admin) : _componentsList(list), _admin(admin) {}

        void update(sf::Time elapsed);

        void manageAnim(int id);
        void makeAnim(int id);
    private:
        std::vector<std::shared_ptr<IComponent>>& _componentsList;
        EntityManager& _admin;
};