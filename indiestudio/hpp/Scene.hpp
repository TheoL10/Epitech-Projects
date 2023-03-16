#pragma once

#include "IScene.hpp"

class Scene : public IScene
{
    public:
        ~Scene() {};

        void draw() {  }
        void update() { }
        void setLvls(int) { }
        void setMap(int, std::vector<int>) {}

    private:
        std::vector<std::unique_ptr<Entity>> _entities;
};