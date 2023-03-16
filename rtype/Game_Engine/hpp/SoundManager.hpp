#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <map>

class SoundManager {
    public:
        void setSoundBuffer(std::string path)
        {
            if (!_soundBuffMap.count(path)) {
                _soundBuffMap[path].loadFromFile(path);
                _sounds[path].setBuffer(_soundBuffMap[path]);
            }
        }

        void playSound(std::string path)
        {
            _sounds[path].play();
        }
    private:
        std::map<std::string, sf::SoundBuffer> _soundBuffMap;
        std::map<std::string, sf::Sound> _sounds;
};