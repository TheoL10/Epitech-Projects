#pragma once

#include "Entity.hpp"

class Bonus : public Entity {
    public:
        Bonus(Model& model, float x, float y, float scale, std::string name, int type, int coord_x, int coord_z) {
            _model = model;
            _pos = {x, 0.0f, y};
            _scale = scale;
            _name = name;
            _isRunning = true;
            _x = x;
            _z = y;
            _type = type;
            _coord_x = coord_x;
            _coord_z = coord_z;
        }
        ~Bonus() {}

        void draw(void)
        {
            if (getIsRunning() == true) {
                raylib.drawModelEx(this->_model, {_x, _height, _z}, { 0.0f, 1.0f, 0.0f }, this->_rotation_state, { this->_scale, this->_scale, this->_scale }, WHITE);
                this->_rotation_state += 1;
                this->_height += _dif;
                if (this->_height > 2.5f || this->_height < 1.5f)
                    _dif = _dif * (-1);
            }
        }
        Vector3 getPos(void) {return _pos;};
        void setPos(Vector3 pos) {_pos = pos;}
        void setX(float x) {_pos.x = x;}
        void setZ(float z) {_pos.z = z;}
        bool getIsRunning(void) {return _isRunning;}
        void setIsRunning(bool isRunning) {this->_isRunning = isRunning;}
        void setName(std::string name) {_name = name;}
        int getCoordX(void) {return _coord_x;}
        int getCoordZ(void) {return _coord_z;}
        int getType(void) {return _type;}

        std::string getName(void) {return _name;};
        Raylib getRayLib(void) {return raylib;}
    private:
        Model _model;
        Vector3 _pos;
        float _scale;
        std::string _name;
        bool _isRunning;
        float _rotation_state = 0.0f;
        float _height = 1.5f;
        float _x;
        float _z;
        float _dif = 0.01f;
        int _coord_x;
        int _coord_z;
        int _type;
        Raylib raylib;
};