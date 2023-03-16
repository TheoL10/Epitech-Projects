#pragma once

#include "Entity.hpp"

class Button : public Entity {
    public:
        Button(Texture2D& button, Texture2D& buttonHover, int x, int y, float scale, float scaleHover, int offsetHover) {
            this->_texture = button;
            this->_texture_hover = buttonHover;

            this->_texture.width = this->_texture.width * scale;
            this->_texture.height = this->_texture.height * scale;
            this->_is_hover = false;

            this->_texture_hover.width *= scaleHover;
            this->_texture_hover.height *= scaleHover;

            this->_pos_x = x;
            this->_pos_y = y;
            _pos.x = x;
            _pos.y = y;
            _posHov.x = x + offsetHover;
            _posHov.y = y;

            this->_offsetHover = offsetHover;
        }
        ~Button() {}

        void draw(void) {
            if (_is_hover)
                raylib.drawTextureEx(_texture_hover, _posHov, 0.0f, 1.0f, WHITE); 
            else
                raylib.drawTextureEx(_texture, _pos, 0.0f, 1.0f, WHITE);
        }

        void setHover(bool hover) { this->_is_hover = hover; }
        bool is_hover() { return this->_is_hover; }
        std::string getName(void) { return "button";};
        Raylib getRayLib(void) {return raylib;}
    private:
        Texture2D _texture;
        Texture2D _texture_hover;
        bool _is_hover;

        int _pos_x;
        int _pos_y;
        Vector2 _pos;
        Vector2 _posHov;

        int _offsetHover;
        Raylib raylib;
};
