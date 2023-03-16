#pragma once

#include "Entity.hpp"

class Image2D : public Entity {
    public:
        Image2D(Texture2D& button, int x, int y, std::string name) {
            this->_texture = button;
            this->_name = name;
            this->_pos_x = x;
            this->_pos_y = y;
            _pos.x = x;
            _pos.y = y;
        }
        ~Image2D() {}

        void draw(void) {
            raylib.drawTextureEx(_texture, _pos, 0.0f, 1.0f, RAYWHITE); 
        }
        void setX(float myCoordx) { _pos.x = myCoordx; }
        void setY(float myCoordy) { _pos.y = myCoordy; }
        float getX(void) { return _pos.x; }
        float getY(void) { return _pos.y; }
        std::string getName(void) { return _name; }
    private:
        Texture2D _texture;

        std::string _name;

        int _pos_x;
        int _pos_y;
        Vector2 _pos;
        Raylib raylib;
};
