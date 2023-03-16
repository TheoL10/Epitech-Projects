#pragma once
#include "Component.hpp"

class ColisionComponent : public Component {
    public:
        ColisionComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin) {}
        ColisionComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin, EntityType type) : _siblings(sibling), _admin(admin), _type(type) {}

        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }

        void setEntityType(EntityType type) { _type = type; }
        EntityType getEntityType() { return _type; }
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        EntityType _type = NEUTRAL;
};