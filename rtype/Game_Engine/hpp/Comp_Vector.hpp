#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class VectorComponent : public Component {
    public:
        VectorComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin) {}
        VectorComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin, float vecX, float vecY) : _siblings(sibling), _admin(admin), _vecX(vecX), _vecY(vecY) {}

        float getVectorX() {return _vecX;}
        float getVectorY() {return _vecY;}

        void setVectorX(float x) {_vecX = x;}
        void setVectorY(float y) {_vecY = y;}

        std::string getNameComp() {return "Vector";}
    protected:
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        float _vecX = 0;
        float _vecY = 0;
};
