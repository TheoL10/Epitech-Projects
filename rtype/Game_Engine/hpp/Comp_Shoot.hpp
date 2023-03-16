#pragma once
#include "Component.hpp"
#include "EntityManager.hpp"

class ShootComponent : public Component {
    public:
        ShootComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin, std::string path) : _siblings(sibling), _path(path), _admin(admin) {}

        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }

        std::string getPath() { return _path; }
        sf::Time getTimeBeforeLastShoot() { return _timeBeforeLastShoot; }
        float getShootPerSecond() { return _shootPerSecond; }
        float getSize() { return _size; }
        bool getWantToShoot() { return _wantToShoot; }

        void setSize(float size) { _size = size; }
        void setShootPerSecond(float shootPerSec) { _shootPerSecond = shootPerSec; }
        void setShootTime() { _timeBeforeLastShoot = _clock.getElapsedTime(); }
        void setWantToShoot(bool state) { _wantToShoot = state; }
        void resetShootTime() {
            _clock.restart();
            _timeBeforeLastShoot = sf::Time::Zero;
        }

        void setAutoShoot(bool autoShoot) { _autoSoot = autoShoot; }
        bool getAutoShoot() { return _autoSoot; }
        void setVecAutoShoot(sf::Vector2f vec) { _vecAutoShoot = vec; }
        sf::Vector2f getVecAutoShoot() { return _vecAutoShoot; }

    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        std::string _path;
        EntityManager& _admin;

        float _shootPerSecond = 1;
        float _size = 1;

        bool _autoSoot = false;
        sf::Vector2f _vecAutoShoot = {0, 0};

        bool _wantToShoot = false;
        sf::Clock _clock;
        sf::Time _timeBeforeLastShoot;
};