#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>

class TextureManager {
    public:
        sf::Texture getTexture(std::string path) {
            if (_textureMap.count(path))
                return _textureMap[path];
            _textureMap[path].loadFromFile(path);
            return _textureMap[path];
        }
    private:
        std::map<std::string, sf::Texture> _textureMap;
};