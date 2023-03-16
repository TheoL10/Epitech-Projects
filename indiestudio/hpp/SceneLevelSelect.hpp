#pragma once

#include <string>

#include "Button.hpp"
#include "Image2D.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "MenuManager.hpp"

class Engine;

class MenuManager;

class SceneLevelSelect : public Scene
{
    public:
        SceneLevelSelect(std::map<std::string, Texture2D>& sprites, std::map<std::string, Model>& models, Engine* engine, MenuManager *manager);
        ~SceneLevelSelect();
        
        void draw();
        void update();
        void setMap(int) {};
        void setLvl(int lvl);
        void setControlers(int a) {};

        void changeLevel(int direction);
    private:
        std::vector<std::unique_ptr<Entity>> _entities;
        std::vector<std::unique_ptr<Entity>> _3Dentities;

        std::map<std::string, Texture2D> _sprites;
        std::map<std::string, Model> _models;

        Engine* _engine;
        MenuManager* _manager;

        int _currLvl = 1;
        int _lvlUnlocked = 1;
        Raylib raylib;
};