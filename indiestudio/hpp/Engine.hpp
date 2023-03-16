#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include "Entity.hpp"
#include "MenuManager.hpp"
#include "SceneGame.hpp"
#include "ScenePause.hpp"
#include "process.hpp"

class Process;

class Engine {
    public:
        Engine();
        ~Engine();

        void setVolume(float);
        void setFps(int);
        void setLevelUnlock(int unlocked, int idSave) { 
            _levelUnlock = unlocked; 
            _idSave = idSave;
        }
        int getFps(void) { return _fps; }
        int getLevelUnlock(void) { return _levelUnlock; };
        void setCamera(int id);
        void setScene(std::string idScene) { _currSceneId = idScene; };
        void setMap(int idMap) { _sceneList["game"]->setMap(idMap, {0, 1, 2, 3}); };
        void setupVersus(int nbManettes, std::vector<int>);
        void initScene(void);
        void initSounds(void);
        void initAnims(void);
        void initModels(void);
        void initSprites(void);
        void initAll(void);
        void destroyAll(void);
        void leaveGame(void) { _leaveGame = true; }
        void playSound(std::string id) { PlaySoundMulti(_sounds[id]); }
        void gameLoop();
        int getCurrentSave() {return _idSave;}
        Camera3D getCamera() { return _camera;}
        void setSaveOnce(int i) {_saveOnce = i;}
        int getSaveOnce() {return _saveOnce;}
        void resetGame(void);
        void setLvl(int lvl);

    private:
        std::string _currSceneId = "menu";
        std::map<std::string, IScene*> _sceneList;

        std::map<std::string, Model> _models;
        std::map<std::string, Texture2D> _sprites;
        std::map<std::string, ModelAnimation*> _anims;
        std::map<std::string, unsigned int> _animsCount;
        std::map<std::string, Music> _musics;
        std::map<std::string, Sound> _sounds;
        Raylib raylib;

        Camera _camera = { 0 };
        int _fps;
        bool _leaveGame = false;


        int _idSave = 0;
        int _levelUnlock = 1;
        int _saveOnce = 0;
};
