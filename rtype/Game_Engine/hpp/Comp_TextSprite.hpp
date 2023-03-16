#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class TextureSpriteComp : public Component {
    public:
        TextureSpriteComp(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin, std::string path);

        void setTextureRect(sf::IntRect newIntRect);
        void setScale(float scX, float scY);

        sf::Vector2f getRealSize() {
            return sf::Vector2f(_frameIntRect.width * _scale.x, _frameIntRect.height * _scale.y);
        }
        sf::Vector2f getScale() { return _scale; }

        sf::IntRect getTextRect() { return _frameIntRect; }

        std::string getPath() { return _path; }
        sf::Sprite& getSprite() {return _sprite;}
        std::string getNameComp() {return "textSprite";}
        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;
        std::string _path;

        sf::Texture _text;
        sf::Sprite _sprite;

        sf::IntRect _frameIntRect;    
        sf::Vector2f _scale;
};