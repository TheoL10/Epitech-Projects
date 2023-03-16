#pragma once

#include "EntityManager.hpp"
#include "Comp_Position.hpp"
#include "Comp_Event.hpp"

class EventShoot : public EventComponent {
    public:
        EventShoot(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin) {}
        std::string getNameComp() {return "MOINS BIZARRE";}
        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }
        void onDeath();
        void onRightScreen();
        void onLeftScreen();
        void onColision(ComponentR thisComp, ComponentR colidComp, EntityType colideType); 

    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;
};