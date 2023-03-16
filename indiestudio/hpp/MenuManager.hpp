#pragma once

#include "Button.hpp"
#include "Image2D.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include "SceneMenu.hpp"
#include "SceneSettings.hpp"
#include "SceneSaveSelect.hpp"
#include "SceneLevelSelect.hpp"
#include "SceneVersus.hpp"

class Engine;

class MenuManager : public Scene
{
    public:
        MenuManager(std::map<std::string, Texture2D>& sprites, std::map<std::string, Model>& models, std::map<std::string, Music>& musics, Engine* engine);
        ~MenuManager();
        
        void draw();
        void update();
        void moveSprite();
        void setMap(int) {};
        void setMenu(std::string idMenu) { _currMenu = idMenu; }
        void setLvl(int lvl) { _menuList["level"]->setLvl(lvl); };
        void setControlers(int a) {};
        void setLvls(int lvl);

        void findNewIdButton(int direction);
    private:
        std::vector<std::unique_ptr<Entity>> _entities;

        std::map<std::string, Texture2D> _sprites;
        std::map<std::string, Model> _models;
        std::map<std::string, Music> _musics;

        std::map<std::string, IScene*> _menuList;

        std::string _currMenu = "saveSelect";

        Engine* _engine;
        Raylib raylib;
};