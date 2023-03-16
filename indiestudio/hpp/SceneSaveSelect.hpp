#pragma once

#include <string>

#include "Button.hpp"
#include "Image2D.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "MenuManager.hpp"

class Engine;

class MenuManager;

class SceneSaveSelect : public Scene
{
    public:
        SceneSaveSelect(std::map<std::string, Texture2D>& sprites, Engine* engine, MenuManager *manager);
        ~SceneSaveSelect();
        
        void draw();
        void update();
        void moveSprite();
        void setMap(int) {};
        void setLvl(int) {};
        void setControlers(int a) {};

        void updateLogo();
        void setSave();

        int findNewIdButton(int currButton, int direction, int left, int right);
    private:
        std::vector<std::unique_ptr<Entity>> _entities;

        std::map<std::string, Texture2D> _sprites;

        int _currButton = 1;

        Engine* _engine;
        MenuManager* _manager;

        int _save1 = 1;
        int _save2 = 1;
        int _save3 = 1;

        int _logoState = 1;

        bool _isSaveSelect = false;

        int _saveState = 3;
        Raylib raylib;
};