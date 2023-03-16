#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class PositionComponent : public Component {
    public:
        PositionComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin) {}
        PositionComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin, float x, float y) : _siblings(sibling), _admin(admin), _x(x), _y(y) {}

        float getX() {return _x;}
        float getY() {return _y;}

        void setPos(float x, float y) {
            _x = x;
            _y = y;
        }

        std::string getNameComp() {return "Position";}
        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        float _x = 0;
        float _y = 0;
};