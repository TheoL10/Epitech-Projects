/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** Fridge
*/

#ifndef FRIDGE_HPP_
#define FRIDGE_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <pthread.h>
#include <stdlib.h>
#include <exception>
#include <typeinfo>
#include <signal.h>
#include <stdexcept>

class Fridge {
    public:
        Fridge() {
            _doe = 5;
            _tomato = 5;
            _gruyere = 5;
            _ham = 5;
            _mushroom = 5;
            _steak = 5;
            _eggplant = 5;
            _goat_cheese = 5;
            _chief_love = 5;
            _afk = 0;
        };
        ~Fridge();
        int _retrieve_ingredients(std::string pizza);
        void refill_once();
        void printFridge(void);
        int getAfk(void) {return _afk;};

    protected:
    private:
        int _tomato;
        int _doe;
        int _ham;
        int _gruyere;
        int _steak;
        int _mushroom;
        int _goat_cheese;
        int _eggplant;
        int _afk;
        int _chief_love;
};

#endif /* !FRIDGE_HPP_ */
