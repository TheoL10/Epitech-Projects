#pragma once

#include "../../../Game_Engine/hpp/EntityManager.hpp"
#include "../../../Game_Engine/hpp/Comp_Position.hpp"
#include "../../../Game_Engine/hpp/Comp_Event.hpp"

class MyEvent : public EventComponent {
    public:
        MyEvent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin) {}
        std::vector<std::shared_ptr<IComponent>>& getSiblings() { return _siblings; }

        // void onDeath();
        // void onRightScreen();
        // void onLeftScreen();
        void onColision(ComponentR thisComp, ComponentR colidComp, EntityType colideType);

    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;
};