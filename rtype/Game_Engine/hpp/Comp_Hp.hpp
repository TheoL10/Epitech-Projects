#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class HpComponent : public Component {
    public:
        HpComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin, int hp) : _siblings(sibling), _admin(admin), _hp(hp) {}

        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }

        int getHp() {return _hp;}
        void setHp(int hp) {_hp = hp;}
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        int _hp = 1;
};