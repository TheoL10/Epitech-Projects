#pragma once

#include "Entity.hpp"

class Block3D : public Entity {
    public:
        Block3D(Model& model, float x, float y, float scale, std::string name) {
            _model = model;
            _pos = {x, 0.0f, y};
            _scale = scale;
            _name = name;
            _isRunning = true;
        }
        ~Block3D() {}

        void draw(void)
        {
            if (getIsRunning() == true)
                raylib.drawModel(_model, _pos, _scale, WHITE);
        }
        Vector3 getPos(void) {return _pos;};
        void setPos(Vector3 pos) {_pos = pos;}
        void setX(float x) {_pos.x = x;}
        void setY(float y) {_pos.y = y;}
        void setZ(float z) {_pos.z = z;}
        bool getIsRunning(void) {return _isRunning;}
        void setIsRunning(bool isRunning) {this->_isRunning = isRunning;}
        void setName(std::string name) {_name = name;}

        void setScale(float scale) {_scale = scale;}
        float getScale(void) {return _scale;}
        std::string getName(void) {return _name;};
        Raylib getRayLib(void) {return raylib;}
    private:
        Model _model;
        Vector3 _pos;
        float _scale;
        std::string _name;
        bool _isRunning;
        Raylib raylib;
};