#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class MoveComponent : public Component {
    public:
        MoveComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin) {}

        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }

        void setMovX(float movX) { _movX = movX; }
        void setMovY(float movY) { _movY = movY; }

        float getMovX() { return _movX; }
        float getMovY() { return _movY; }
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        float _movX = 0;
        float _movY = 0;
};