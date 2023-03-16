#pragma once

#include "EntityType.hpp"
#include "System.hpp"
#include "Comp_Move.hpp"
#include "Comp_Position.hpp"
#include "Comp_Shoot.hpp"
#include "Comp_Scene.hpp"
#include "Comp_Anim.hpp"
#include "Comp_Sound.hpp"

class EventSystem : public System {
    public:
        EventSystem(std::vector<std::shared_ptr<IComponent>>& list, EntityManager& admin, sf::RenderWindow& window) : _componentsList(list), _admin(admin), _window(window) {
            _timeRatio = 0;

            for (int i = 0; i < 100; i++)
                _keysPressed[i] = false;
        }

        void update(sf::Time elapsed);
        void checkMoveComp(int id);
        void checkShootComp(int id);
        void checkAnimComp(int id);
        void checkSoundComp(int id);

        void setKeyboardsInput(std::map<int, bool[100]> playersInputs);
        void setPlayersInput(int idPlayer);
    private:
        std::vector<std::shared_ptr<IComponent>>& _componentsList;
        EntityManager& _admin;
        sf::RenderWindow& _window;

        bool _keysPressed[100];
        std::map<int, bool[100]> _playersInputs;
        sf::Event _event;

        float _timeRatio;

        sf::Vector2i _mouseClickPosition = {-1, -1};
};