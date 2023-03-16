#pragma once

#include "Button.hpp"
#include "Image2D.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "MenuManager.hpp"

class Engine;

class MenuManager;

class SceneVersus : public Scene
{
    public:
        SceneVersus(std::map<std::string, Texture2D>& sprites, Engine* engine, MenuManager *manager);
        ~SceneVersus();
        
        void draw();
        void update();
        void updateManette(int id);
        void moveSprite();
        void setMap(int) {};
        void setLvl(int) {};
        void setControlers(int a) {};

        void updateLogo();
        void setSave();

        int countManettes(void);

        int findNewIdButton(int currButton, int direction, int left, int right);
    private:
        std::vector<std::unique_ptr<Entity>> _entities;
        std::map<std::string, Texture2D> _sprites;

        std::vector<int> _charList = {1, 5, 9, 13};

        Engine* _engine;
        MenuManager* _manager;
        Raylib raylib;
};