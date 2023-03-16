#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class GravityComponent : public Component {
    public:
        GravityComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin) {}

        float getG() {return _g;}

        std::string getNameComp() {return "Gravity";}
        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        float _g = 0.25;
        int _id = 2;
};