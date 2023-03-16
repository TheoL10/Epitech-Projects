#pragma once

#include "Button.hpp"
#include "Image2D.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "MenuManager.hpp"

class Engine;

class MenuManager;

class SceneMenu : public Scene
{
    public:
        SceneMenu(std::map<std::string, Texture2D>& sprites, Engine* engine, MenuManager *manager);
        ~SceneMenu();
        
        void draw() { 
            for (int i = 0; i < _entities.size(); i++)
             _entities[i]->draw();
             if (is_select == true)
                _select->draw();}
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
        std::map<std::string, Music> _musics;

        int _currButton = 1;

        Engine* _engine;
        MenuManager* _manager;
        Raylib raylib;
        bool is_select = false;
        std::unique_ptr<Entity> _select;
};