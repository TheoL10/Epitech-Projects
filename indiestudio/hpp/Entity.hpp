#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include "raylib.hpp"

class Entity {
    public:
        ~Entity() {};

        virtual void draw() {};
        virtual void setHover(bool hover) {};
        virtual std::string getName(void) {return _name;}
        virtual Vector3 getPos(void) {return {0.0f, 0.0f, 0.0f};};
        virtual void setX(float x) {}
        virtual void setY(float y) {}
        virtual void setZ(float z) {}
        virtual float getX(void) {return 0.0f;}
        virtual float getY(void) {return 0.0f;}
        virtual float getZ(void) {return 0.0f;}
        virtual void setModelFrame(void) {}
        virtual void setRotation(int rotation) {}
        virtual float getTimeStart(void) {return 0.0f;}
        virtual void setTimeStart(float time) {}
        virtual void setTimeEnd(float time) {}
        virtual float getTimeEnd(void) {return 0.0f;}
        virtual int getOneTime(void) {return 0;}
        virtual void setOneTime(int time) {}
        virtual int getRadius(void) {return 0;}
        virtual void setRadius(float radius) {}
        virtual void setTimeUntilExplosion(float time) {}
        virtual float getTimeUntilExplosion(void) {return 0.0f;}
        virtual float rounderman(float value, unsigned char prec) {return 0.0f;}
        virtual std::string getPathSound(void) {return "";}
        virtual void setIsRunning(bool isRunning) {}
        virtual bool getIsRunning(void) {return true;}
        virtual void setPos(Vector3 pos) {}
        virtual void setName(std::string name) {}
        virtual std::vector<int> order_vector_in_asceding_order(std::vector<int>& vector) {std::vector<int> a; return a;}
        virtual void setScale(float scale) {}
        virtual float getScale(void) {return 0.0f;}

        //ia
        virtual void setWasPos(Vector3 pos) {}
        virtual Vector3 getWasPos(void) {return {0.0f, 0.0f, 0.0f};}
        virtual void setClosestPlayer(std::vector<int> closestPlayer) {}
        virtual void sethasFocus(int hasFocus) {}
        virtual int gethasFocus(void) {return 0;}
        virtual void setClosestPlayerx(int closestPlayerx) {}
        virtual void setClosestPlayerz(int closestPlayerz) {}
        virtual void setMyCoordx(int myCoordx) {}
        virtual void setMyCoordz(int myCoordz) {}
        virtual void setMyCoord(std::vector<int> clost) {}
        virtual int getOneTime2(void) {return 0;}
        virtual void setOneTime2(int time) {}
        virtual void setChecker(int checker) {}
        virtual int getChecker(void) {return 0;}
        virtual void setWasCoord(std::vector<int> wasCoord) {}
        virtual void setOneTime3(int time) {}
        virtual int getOneTime3(void) {return 0;}
        virtual void setCoordBomb(std::vector<int> coordBomb) {}

        //bonus
        virtual int getCoordX(void) {return 0;}
        virtual int getCoordZ(void) {return 0;}
        virtual int getType(void) {return 0;}

        //player
        virtual float getSpeed(void) {return 0.0f;}
        virtual void setSpeed(float speed) {}
        virtual int getMaxBomb(void) {return 0;}
        virtual void setMaxBomb(int maxBomb) {}
        virtual int getBombRange(void) {return 0;}
        virtual void setBombRange(int bombRange) {}
        std::string _name;

        virtual Raylib getRayLib(void) {Raylib a; return a;}
        virtual void setIsDead(bool isDead) {}
        virtual bool getIsDead(void) {return false;}

        virtual int getBombStock() {return _currentBombStock;}
        virtual void addBombStock() {_currentBombStock += 1;}
        virtual void removeBombStock() {_currentBombStock -= 1;}
        virtual std::string getOwner() {return "";}
        int _currentBombStock = 0;

        virtual std::vector<int> getClosestPlayer(void) {std::vector<int> a; return a;};
        virtual std::vector<int> getMyCoord(void) {std::vector<int> a; return a;};
        virtual std::vector<int> getWasCoord(void) {std::vector<int> a; return a;};
        virtual std::vector<int> getCoordBomb(void) {std::vector<int> a; return a;};
};
