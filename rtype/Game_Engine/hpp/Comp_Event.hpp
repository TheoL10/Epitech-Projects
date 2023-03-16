#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class IEventComponent : public Component {
    public:
        virtual ~IEventComponent() = default;
        virtual std::string getNameComp() = 0;
        virtual std::vector<std::shared_ptr<IComponent>>& getSiblings() = 0;
        virtual void onDeath() = 0;
        virtual void onRightScreen() = 0;
        virtual void onLeftScreen() = 0;
        virtual void onColision(ComponentR, ComponentR, EntityType) = 0;
        virtual void setPlayerId(int) = 0;
        virtual int getPlayerId() = 0;
};

class EventComponent : public IEventComponent {
    public:
        ~EventComponent() {}
        std::string getNameComp() {return "BIZARRE";}
        std::vector<std::shared_ptr<IComponent>>& getSiblings() {std::vector<std::shared_ptr<IComponent>> *a = new std::vector<std::shared_ptr<IComponent>>; return *a;}
        void onDeath() {}
        void onRightScreen() {}
        void onLeftScreen() {}
        void onColision(ComponentR, ComponentR, EntityType) {}
        void setPlayerId(int) {}
        int getPlayerId() { return 0; }
};