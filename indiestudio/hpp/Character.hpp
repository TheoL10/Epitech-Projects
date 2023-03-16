/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** Character
*/

#pragma once

#include "Entity.hpp"

class Character : public Entity {
    public:
        Character(Model& model, ModelAnimation* anim,float x, float y, float scale, std::string name) {
            _model = model;
            _pos = {x, 0.0f, y};
            _scale = scale;
            _name = name;
            _anim = anim;
            _isRunning = true;
            _bombRange = 1;
        }
        ~Character() {}

        void draw(void) { 
            if (_name == "broken" || _name == "finito")
                return;
            if (_isRunning == true) {
                if (_rotation == 0) // def
                    raylib.drawModelEx(this->_model, this->_pos, _rotationAxis, _rotationAngle, { this->_scale, this->_scale, this->_scale }, WHITE);
                if (_rotation == 1) //right
                    raylib.drawModelEx(this->_model, this->_pos, { 0.0f, 1.0f, 1.0f }, -180.0f, { this->_scale, this->_scale, this->_scale }, WHITE);
                if (_rotation == 2) //left
                    raylib.drawModelEx(this->_model, this->_pos, { 1.0f, 0.0f, 0.0f }, -90.0f, { this->_scale, this->_scale, this->_scale }, WHITE);
                if (_rotation == 3) //up
                    raylib.drawModelEx(this->_model, this->_pos, { 1.0f, 1.0f, 1.0f }, -125.0f, { this->_scale, this->_scale, this->_scale }, WHITE);
                if (_rotation == 4) //down
                   raylib.drawModelEx(this->_model, this->_pos, { -1.0f, 1.0f, 1.0f }, 125.0f, { this->_scale, this->_scale, this->_scale }, WHITE);
            }
        }
        Vector3 getPos(void) {return _pos;};
        void setPos(Vector3 newPos) {_pos = newPos;};
        void setRotation(int rotation) {_rotation = rotation;}
        void setRotationAxis(Vector3 axis) {_rotationAxis = axis;}
        void setRotationAngle(float angle) {_rotationAngle = angle;}
        void setModelFrame(void) {
            _animFrameCounter++;
            raylib.updateModelAnimation(_model, _anim[0], _animFrameCounter);
            if (_animFrameCounter >= _anim[0].frameCount) _animFrameCounter = 0;
        }
        void setX(float x) {_pos.x = x;}
        void setIsRunning(bool isRunning) {this->_isRunning = isRunning;}
        bool getIsRunning(void) {return _isRunning;}
        void setZ(float z) {_pos.z = z;}
        float rounderman(float value, unsigned char prec) {
            float pow_10 = pow(10.0f, (float)prec);
            return round(value * pow_10) / pow_10;
        };
        Raylib getRayLib(void) {return raylib;}

        //ia

        void setWasPos(Vector3 pos) {_wasPos = pos;}
        Vector3 getWasPos(void) {return _wasPos;}


        std::string getName(void) {return _name;};
        void setName(std::string name) {_name = name;}
        void setScale(float scale) {_scale = scale;}
        float getScale(void) {return _scale;}

        float getSpeed(void) {return _speed;}
        void setSpeed(float speed) {_speed = speed;}
        int getMaxBomb(void) {return _maxBomb;}
        void setMaxBomb(int maxBomb) {_maxBomb = maxBomb;}
        int getBombRange(void) {return _bombRange;}
        void setBombRange(int bombRange) {_bombRange = bombRange;}
         void setClosestPlayer(std::vector<int> closestPlayer) {_closestPlayer = closestPlayer;};
        void setClosestPlayerx(int closestPlayerx) {_closestPlayer[0] = closestPlayerx;}
        void setClosestPlayerz(int closestPlayerz) {_closestPlayer[1] = closestPlayerz;}
        std::vector<int> getClosestPlayer(void) {return _closestPlayer;}
        void sethasFocus(int hasFocus) {_hasFocus = hasFocus;}
        int gethasFocus(void) {return _hasFocus;}
        void setMyCoordx(int myCoordx) {_myCoord[0] = myCoordx;}
        void setMyCoordz(int myCoordz) {_myCoord[1] = myCoordz;}
        void setMyCoord(std::vector<int> myCoord) {_myCoord = myCoord;};
        std::vector<int> getMyCoord(void) {return _myCoord;};
        float getTimeStart(void) {return timeStart;}
        void setTimeStart(float time) {timeStart = time;}
        void setTimeEnd(float time) {timeEnd = time;}
        float getTimeEnd(void) {return timeEnd;}
        int getOneTime(void) {return one_time;}
        void setOneTime(int time) {one_time = time;}
        int getOneTime2(void) {return one_time2;}
        void setOneTime2(int time) {one_time2 = time;}
        void setChecker(int checker) {_checker = checker;}
        int getChecker(void) {return _checker;}
        void setWasCoord(std::vector<int> wasCoord) {_wasCoord = wasCoord;};
         std::vector<int> getWasCoord(void) {return _wasCoord;}
        void setOneTime3(int time) {one_time3 = time;}
        int getOneTime3(void) {return one_time3;}
        void setCoordBomb(std::vector<int> coordBomb) {_coordBomb = coordBomb;};
         std::vector<int> getCoordBomb(void) {return _coordBomb;}
        void setIsDead(bool isDead) {_isDead = isDead;}
        bool getIsDead(void) {return _isDead;}
        int getBombStock() {return _currentBombStock;}
        void addBombStock() {_currentBombStock += 1;}
        void removeBombStock() {_currentBombStock -= 1;}
    private:
        Model _model;
        ModelAnimation* _anim;
        Vector3 _pos;
        float _scale;
        std::string _name;
        Vector3 _rotationAxis = { 1.0f, 0.0f, 0.0f };
        float _rotationAngle = -90.0f;
        int _modelDirection = 0;
        int _animFrameCounter = 0;
        int _rotation = 0;
        bool _isRunning;
        Vector3 _wasPos;
        float _speed = 0.1f;
        int _maxBomb = 1;
        int _currentBombStock = 1;
        int _bombRange = 1;
        std::vector<int> _closestPlayer = {0, 0, 0, 0};
        int _hasFocus = 0;
        int _myCoordx = 0;
        int _myCoordz = 0;
        std::vector<int> _myCoord = {0, 0, 0, 0};
        float timeStart = 0.0f;
        float timeEnd = 0.0f;
        int one_time = 0;
        int one_time2 = 0;
        int one_time3 = 0;
        int _checker = 0;
        std::vector<int> _wasCoord = {0, 0, 0, 0};
        std::vector<int> _coordBomb = {0, 0, 0, 0};
        Raylib raylib;
        bool _isDead = false;
};
