#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class SoundComponent : public Component {
    public:
        SoundComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin);
        std::string getNameComp() {return "sound";}
        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }

        void setSoundKey(sf::Keyboard::Key key, std::string path);
        void setSoundDeath(std::string path);
        void playSoundKeyboard(sf::Keyboard::Key key);
        void playSoundDeath();
        void playSoundShoot();
        void setSoundShoot(std::string path);

        void setPathPlaying(std::string path) { _pathPlaying = path; }
        std::string getPathPlaying() { return _pathPlaying; }
    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        std::map<sf::Keyboard::Key, std::string> _keySounds;
        std::string _onDeath = "";
        std::string _onShoot = "";

        std::string _pathPlaying = "";
};