/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

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

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

class Pizza {
    public:
        Pizza(std::string type, std::string size) {
            this->_type = type;
            this->_size = size;
            };
        ~Pizza() {};
        std::string get_type() {return _type;};
        std::string get_size() {return _size;};
    protected:
    private:
        std::string _type;
        std::string _size;
};

#endif /* !PIZZA_HPP_ */
