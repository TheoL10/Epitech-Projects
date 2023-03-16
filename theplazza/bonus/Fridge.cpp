/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** Fridge
*/

#include "hpp/Fridge.hpp"

Fridge::~Fridge()
{
}

void Fridge::printFridge(void)
{
    printf("\nIngredients:\n%d dough, %d tomatoes, %d eggplants, %d goat cheese, %d steaks, %d ham, %d mushrooms, %d gruyere, %d chief love\n", _doe, _tomato, _eggplant, _goat_cheese, _steak, _ham, _mushroom, _gruyere, _chief_love);
}

int Fridge::_retrieve_ingredients(std::string pizza)
{
    _afk = 0;
    if (pizza == "Margarita") {
        if (_doe > 0 && _tomato > 0 && _gruyere > 0) {
            _doe--;
            _tomato--;
            _gruyere--;
            return (0);
        }
        else
            return (1);
    }
    if (pizza == "Regina") {
        if (_doe > 0 && _tomato > 0 && _gruyere > 0 && _ham > 0 && _mushroom > 0) {
            _doe--;
            _tomato--;
            _gruyere--;
            _ham--;
            _mushroom--;
            return (0);
        }
        else
            return (1);
    }
    if (pizza == "Americana") {
        if (_doe > 0 && _tomato > 0 && _gruyere > 0 && _steak > 0) {
            _doe--;
            _tomato--;
            _gruyere--;
            _steak--;
            return (0);
        }
        else
            return (1);
    }
    if (pizza == "Fantasia") {
        if (_doe > 0 && _tomato > 0 && _eggplant > 0 &&  _goat_cheese > 0 && _chief_love > 0) {
            _doe--;
            _tomato--;
            _eggplant--;
            _goat_cheese--;
            _chief_love--;
            return (0);
        }
        else
            return (1);

    }
    return (0);
}

void Fridge::refill_once()
{
    if (_chief_love < 5)
        this->_chief_love++;
    if (_doe < 5)
        this->_doe++;
    if (_eggplant < 5)
        this->_eggplant++;
    if (_goat_cheese < 5)
        this->_goat_cheese++;
    if (_gruyere < 5)
        this->_gruyere++;
    if (_ham < 5)
        this->_ham++;
    if (_mushroom < 5)
        this->_mushroom++;
    if (_steak < 5)
        this->_steak++;
    if (_tomato < 5)
        this->_tomato++;
    this->_afk++;
}