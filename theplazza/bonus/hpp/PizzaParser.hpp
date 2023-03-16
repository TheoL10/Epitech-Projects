/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** PizzaParser
*/

#ifndef PIZZAPARSER_HPP_
#define PIZZAPARSER_HPP_
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
#include "Pizza.hpp"



class PizzaParser {
    public:
        PizzaParser();
        ~PizzaParser();
        std::vector<std::string> str_to_str_array(std::string str);
        int check_content(std::vector<std::string> str_array);
        std::vector<Pizza> create_queue(std::string *str_array);
    protected:
    private:
        int isNumber(std::string str);
        std::vector<Pizza> _pizza_queue;
};

#endif /* !PIZZAPARSER_HPP_ */
