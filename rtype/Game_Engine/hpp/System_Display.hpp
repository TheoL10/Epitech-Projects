#pragma once

#include "EntityManager.hpp"
#include "System.hpp"
#include "Comp_Position.hpp"
#include "Comp_TextSprite.hpp"
#include "Comp_Scene.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

class DisplaySystem : public System {
    public:
        DisplaySystem(std::vector<std::shared_ptr<IComponent>>& list, EntityManager& admin, sf::RenderWindow& window) : _componentsList(list), _admin(admin),_window(window) {}

        void update(sf::Time elapsed);
        std::string getNameSys() {return "Display";}
    private:
        std::vector<std::shared_ptr<IComponent>>& _componentsList;
        EntityManager& _admin;
        sf::RenderWindow& _window;
};