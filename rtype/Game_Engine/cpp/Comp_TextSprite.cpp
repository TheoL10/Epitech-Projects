#include "../hpp/Comp_TextSprite.hpp"

TextureSpriteComp::TextureSpriteComp(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin, std::string path) : _siblings(sibling), _admin(admin)
{
    _path = path;
    _text = _admin.getTextureManager().getTexture(path);
    _sprite.setTexture(_text);

    int sizeTextX = (int)_text.getSize().x;
    int sizeTextY = (int)_text.getSize().y;

    _frameIntRect = {0, 0, sizeTextX, sizeTextY};
    _scale = {1.0f, 1.0f};
}

void TextureSpriteComp::setTextureRect(sf::IntRect newIntRect)
{
    _frameIntRect = newIntRect;
    _sprite.setTextureRect(_frameIntRect);
}

void TextureSpriteComp::setScale(float scX, float scY)
{
    _scale = {scX, scY};
    _sprite.setScale(_scale);
}