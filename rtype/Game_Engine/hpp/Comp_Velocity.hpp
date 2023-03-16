#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class VelocityComponent : public Component {
    public:
        VelocityComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin) {}
        VelocityComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin, float velX, float velY) : _siblings(sibling), _admin(admin), _velocityX(velX), _velocityY(velY) {}

        float getVelocityX() {return _velocityX;}
        float getVelocityY() {return _velocityY;}

        void setVelocityX(float x) {_velocityX = x;}
        void setVelocityY(float y) {_velocityY = y;}

        std::string getNameComp() {return "Velocity";}
    protected:
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        float _velocityX = 1;
        float _velocityY = 1;
};
