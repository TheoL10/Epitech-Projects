#pragma once

#include "Button.hpp"
#include "Image2D.hpp"
#include "Scene.hpp"
#include "Engine.hpp"

class Engine;

class MenuManager;

class SceneSettings : public Scene
{
    public:
        SceneSettings(std::map<std::string, Texture2D>& sprites, Engine* engine, MenuManager* manager);
        ~SceneSettings();
        
        void draw();
        void update();
        void updateFps();
        void updateFS();
        void updateSound();
        void updateLeave();
        void setMap(int) {};
        void setLvl(int) {};
        void setControlers(int a) {};

        int findNewIdButton(int currButton, int direction, int left, int right);
    private:
        std::vector<std::unique_ptr<Entity>> _entities;
        std::vector<std::unique_ptr<Entity>> _volume;

        std::map<std::string, Texture2D> _sprites;

        int _currButton = 1;
        int _fpsSelected = 6;
        int _currFps = 6;
        int display;

        int _rectSize = 738;
        int _currSound = 10;

        Engine* _engine;
        MenuManager* _manager;
        Raylib raylib;
};