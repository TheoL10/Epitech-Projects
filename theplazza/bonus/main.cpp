/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** main
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>
#include "hpp/Reception.hpp"
#include "hpp/error_handling.hpp"
#include "hpp/PizzaParser.hpp"
#include "hpp/time_gestion.hpp"
#include "hpp/Kitchen.hpp"
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window.h>
#include <SFML/Graphics.hpp>

int main(int argc, char **argv)
{
    std::string buf;
    Error error;
    if (error.error_handling(argc, argv) != 0)
        return (84);
    Reception reception(std::stof(argv[1]), std::stoi(argv[2]), std::stof(argv[3]));
    Kitchen *kitch = new Kitchen(reception._cooking_multiplier, reception._time_until_replace);
    PizzaParser *pizzaParser = new PizzaParser();
    TimeGestion *timeGestion = new TimeGestion();
    std::cout << "Order: ";
    kitch->exec_func(std::bind(&Kitchen::fridge_slave, kitch));
    while (std::getline(std::cin, buf) && buf != "exit") {
        reception._command = buf;
        std::vector<std::string> words = pizzaParser->str_to_str_array(buf);
        if (timeGestion->time() == 84 || pizzaParser->check_content(words) == 84) {
            if (buf == "status" || buf == "Status") {
                kitch->_fridge->printFridge();
            }
            // std::cout << "Invalid order:  TYPE SIZE NUMBER" << std::endl;
        }
        else {
            reception._name_of_pizz = reception._command.substr(0, reception._command.find(" "));
            reception._command = reception._command.substr(reception._command.size() - 3, 3);
            reception._command = reception._command.substr(reception._command.find("x") + 1, reception._command.size() - reception._command.find("x"));
            reception._number_of_pizz = stoi(reception._command.substr(reception._command.find(" ") + 1).substr(0, reception._command.find(" ")));
            if (reception._name_of_pizz == "Margarita")
                kitch->cook_margarita(kitch, reception._number_of_pizz);
            else if (reception._name_of_pizz == "Americana")
                kitch->cook_americana(kitch, reception._number_of_pizz);
            else if (reception._name_of_pizz == "Regina")
                kitch->cook_regina(kitch, reception._number_of_pizz);
            else if (reception._name_of_pizz == "Fantasia") {
                kitch->cook_fantasia(kitch, reception._number_of_pizz);
            }
        else
            std::cout << "Not on the menu" << std::endl;
        }
        // std::cout << "\nOrder: ";
        sf::RenderWindow window(sf::VideoMode(900, 596), "SFML");
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Texture texture2;
        sf::Texture texture3;
        sf::Texture texture4;
        sf::Texture texture5;
        sf::IntRect rect(0, 0, 459, 459);
        sf::IntRect rect3(0, 0, 459, 459);
        sf::IntRect rect4(0, 0, 459, 459);
        sf::IntRect rect5(0, 0, 459, 459);
        sf::Sprite sprite2(texture2, rect);
        sf::Sprite sprite3(texture3, rect3);
        sf::Sprite sprite4(texture4, rect4);
        sf::Sprite sprite5(texture5, rect5);
        sf::Event event;
        sf::Clock clock;
        texture.loadFromFile("picture/kitchen.png");
        texture2.loadFromFile("picture/pizza.png");
        sprite.setTexture(texture);
        sprite2.setTexture(texture2);
        sprite3.setTexture(texture2);
        sprite4.setTexture(texture2);
        sprite5.setTexture(texture2);
        sprite2.setScale(0.1, 0.1);
        sprite3.setScale(0.1, 0.1);
        sprite4.setScale(0.1, 0.1);
        sprite5.setScale(0.1, 0.1);
        sprite2.setPosition(200, 165);
        sprite3.setPosition(650, 165);
        sprite4.setPosition(200, 460);
        sprite5.setPosition(650, 460);
        while (window.isOpen())
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.draw(sprite);
            if (clock.getElapsedTime().asSeconds() > 0.2) {
                if (rect.left == 1437)
                    rect.left = 0;
                else
                    rect.left += 479;
                if (rect3.left == 1437)
                    rect3.left = 0;
                else
                    rect3.left += 479;
                if (rect4.left == 1437)
                    rect4.left = 0;
                else
                    rect4.left += 479;
                if (rect5.left == 1437)
                    rect5.left = 0;
                else
                    rect5.left += 479;
                sprite2.setTextureRect(rect);
                sprite3.setTextureRect(rect3);
                sprite4.setTextureRect(rect4);
                sprite5.setTextureRect(rect5);
                clock.restart();
            }
            if (kitch->_fridge->getAfk() <= 2) {
                sprite2.setPosition(200, 165);
                window.draw(sprite2);
            // window.draw(sprite3);
            // window.draw(sprite4);
            // window.draw(sprite5);
            }
            else {
                sprite2.setPosition(-200, -165);
                window.draw(sprite2);
                window.close();
            }
            window.display();
        }
    }
    return (0);
}
