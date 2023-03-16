/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** Deflagration
*/

#ifndef DEFLAGRATION_HPP_
#define DEFLAGRATION_HPP_
#include "SceneGame.hpp"

class Deflagration : public Entity {
    public:
        Deflagration(Model& model, float x, float y, float scale, std::string name)
        {
            _model = model;
            _pos = {x, 0.0f, y};
            _scale = scale;
            _name = name;
            _isRunning = true;
            timeStart = raylib.getTime();
            timeEnd = timeStart + 0.75;
            one_time = 1;
    }
    ~Deflagration();
    void draw(void)
    {
        if (getIsRunning() == true)
            raylib.drawModel(_model, _pos, _scale, WHITE);
        
    }
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
    std::string getName(void) {return _name;};
    void setName(std::string name) {_name = name;}
    void setIsRunning(bool isRunning) {this->_isRunning = isRunning;}
    bool getIsRunning(void) {return _isRunning;}
    void setScale(float scale) {_scale = scale;}
    float getScale(void) {return _scale;}
    Raylib getRayLib(void) {return raylib;}
    Vector3 getPos(void) {return _pos;}
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
    protected:
    private:
        float timeStart = 0.0f;
        float timeEnd = 0.0f;
        int one_time = 0;
        int radius = 1;
        int timeUntilExplosion = 1;
        Model _model;
        Vector3 _pos;
        float _scale;
        std::string _name;
        bool _isRunning;
        Raylib raylib;
};

#endif /* !DEFLAGRATION_HPP_ */
