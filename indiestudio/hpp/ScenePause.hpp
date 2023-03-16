#pragma once

#include "Button.hpp"
#include "Image2D.hpp"
#include "Scene.hpp"
#include "Engine.hpp"

class Engine;

class ScenePause : public Scene
{
    public:
        ScenePause(std::map<std::string, Texture2D>& sprites, Engine* engine);
        ~ScenePause();
        
        void draw() {for (int i = 0; i < _entities.size(); i++) _entities[i]->draw(); };
        void update();
        void moveSprite();
        void setMap(int) {};
        void setLvl(int) {};
        void setControlers(int a) {};

        void findNewIdButton(int direction);
        Raylib getRaylib() { return raylib; }
    private:
        std::vector<std::unique_ptr<Entity>> _entities;
        std::map<std::string, Texture2D> _sprites;

        int _currButton = 0;

        Engine* _engine;
        Raylib raylib;
};