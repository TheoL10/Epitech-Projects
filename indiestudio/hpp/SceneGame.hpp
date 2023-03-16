#pragma once

#include "Scene.hpp"
#include "process.hpp"
#include "Character.hpp"
#include "Bomb.hpp"
#include "Bonus.hpp"
#include "Engine.hpp"
#include <algorithm>
#include "raylib.hpp"

class Engine;

class SceneGame : public Scene
{
    public:
        SceneGame(std::map<std::string, Model>& models, std::map<std::string, ModelAnimation*>& anims, std::map<std::string, Texture2D>& sprites, std::map<std::string, Music>& musics, Engine* engine);
        ~SceneGame();

        void draw();
        void update();
        void updatePlayer(std::unique_ptr<Entity>& player, int idControler);
        void updateBomb(std::unique_ptr<Entity>& bomb);
        void updateDeflagration(std::unique_ptr<Entity>& deflagration);
        void movePlayer(std::unique_ptr<Entity>& player, Vector2 movement);
        bool checkCollision(Vector3 pos1, float size1, Vector3 pos2, float size2, bool isBomb);
        void updateIA(std::unique_ptr<Entity>& ia);
        void updateIA2(std::unique_ptr<Entity>& ia);
        void updateIA3(std::unique_ptr<Entity>& ia, int id);
        void updateBroken(std::unique_ptr<Entity>& broken);
        void setMap(int) {};
        void setMap(int, std::vector<int>);
        void setLvl(int) {};
        void setControlers(int nb) { _nbControlers = nb; _isVersus = true;};
        float rMan(float value, unsigned char prec) {
            float pow_10 = pow(10.0f, (float)prec);
            return round(value * pow_10) / pow_10;
        };
        void findReachBomb(std::string name, float x, float y, int cx, int cy, int i);
        void IABomb1(std::unique_ptr<Entity>& ia, int oneTime);
        void IABomb2(std::unique_ptr<Entity>& ia, Vector2 newPos, Vector2 newPos2, Vector2 newPos3);
        bool valideInputs(KeyboardKey key, GamepadButton pad, int idControler, std::string state);
        bool isAllPlayerDead(void);
        bool isAllIADead(void);
        int countPlayerRemaining(void);
        void setSave();
        int findLastPlayer(void);
    private:
        std::vector<std::unique_ptr<Entity>> _entities;

        std::map<std::string, Texture2D> _sprites;
        std::map<std::string, Model> _models;
        std::map<std::string, ModelAnimation*> _anims;
        std::map<std::string, Music> _musics;
        Engine* _engine;
        Raylib raylib;
        bool _Player_0_isDead = false;
        bool _Player_1_isDead = false;
        bool _Player_2_isDead = false;
        bool _Player_3_isDead = false;
        std::vector<bool> _isDeadList = {false, false, false, false};

        float _timeEnd = 0;
        bool _oneTime = false;

        int _idMap;
        int _nbControlers = 0;
        bool _isVersus = false;
};