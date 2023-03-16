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
    }
    return (0);
}
