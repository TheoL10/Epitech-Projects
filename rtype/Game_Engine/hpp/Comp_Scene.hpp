#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class SceneComponent : public Component {
    public:
        SceneComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin) {}
        SceneComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin, int idScene) : _siblings(sibling), _admin(admin), _idScene(idScene) {}

        void setIdScene(int idScene) { _idScene = idScene; }
        int getIdScene() { return _idScene; }

        std::string getNameComp() {return "Scene";}
    protected:
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        int _idScene = 0;
};
