/*
** EPITECH PROJECT, 2022
** Sans titre(Espace de travail)
** File description:
** Bomb
*/

#pragma once

#include "Entity.hpp"

class Bomb : public Entity {
    public:
        Bomb(Model& model, float x, float y, float scale, std::string name, int radiuso = 1, float timeUtilExplosiono = 2, std::string owner = "None") {
            _model = model;
            _owner = owner;
            _pos = {x, 0.0f, y};
            _scale = scale;
            _name = name;
            _isRunning = true;
            timeUntilExplosion = timeUtilExplosiono;
            radius = radiuso;
        }
        ~Bomb() {}

        void draw(void) 
        { 
            if (getIsRunning() == true)
                raylib.drawModel(_model, _pos, _scale, WHITE);  
        }
        Vector3 getPos(void) {return _pos;};
        void setX(float x) {_pos.x = x;}
        void setZ(float z) {_pos.z = z;}
        float getTimeStart(void) {return timeStart;}
        void setTimeStart(float time) {timeStart = time;}
        void setTimeEnd(float time) {timeEnd = time;}
        float getTimeEnd(void) {return timeEnd;}
        int getOneTime(void) {return one_time;}
        void setOneTime(int time) {one_time = time;}
        int getRadius(void) {return radius;}
        void setRadius(float radius) {this->radius = radius;}
        void setTimeUntilExplosion(float time) {timeUntilExplosion = time;}
        float getTimeUntilExplosion(void) {return timeUntilExplosion;}
        std::string getPathSound(void) {return _path_sound;}
        void setIsRunning(bool isRunning) {this->_isRunning = isRunning;}
        bool getIsRunning(void) {return _isRunning;}
        float rounderman(float value, unsigned char prec) {
            float pow_10 = pow(10.0f, (float)prec);
            return round(value * pow_10) / pow_10;
        };
        int getCoordX() {
        float x = _pos.x - 0.8;
        float i = 0;
        for (; x >= 0 ; i++) {
            x -= 1.6f;
        }
        i--;
        float posx = (i * 1.6f) + 1.6;
        int coord_x = rounderman(posx / 1.6f, 1);
        return coord_x;
        }
        int getCoordZ() {
        float z = _pos.z - 0.8;
        float i = 0;
        for (; z >= 0 ; i++) {
            z -= 1.6f;
        }
        i--;
        float posz = (i * 1.6f) + 1.6;
        int coord_z = rounderman(posz / 1.6f, 1);
        return coord_z;
        }

        void setScale(float scale) {_scale = scale;}
        float getScale(void) {return _scale;}
        std::string getName(void) {return _name;};
        void setName(std::string name) {_name = name;}
        Raylib getRayLib(void) {return raylib;}
        std::string getOwner() {return _owner;}

    private:
        Model _model;
        Vector3 _pos;
        float _scale;
        std::string _name;
        float timeStart = 0.0f;
        float timeEnd = 0.0f;
        int one_time = 0;
        int radius = 1;
        int timeUntilExplosion = 2;
        std::string _path_sound = "../assets/Explosion/boom/bien.ogg";
        bool _isRunning;
        Raylib raylib;
        std::string _owner;

};
