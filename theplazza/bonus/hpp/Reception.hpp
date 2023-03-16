/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** reception
*/

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

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_


class Reception {
    public:
        Reception(float cooking_multitplier, int number_cooks, float time_until_replace);
        ~Reception() {};
        int error_handling(int argc, char **argv);
        int check_numbers(char *a, char *b, char *c);
        int show_usage(void);
        float _cooking_multiplier;
        int _number_cooks;
        float _time_until_replace;
        std::string _kitchen_status;
        std::string _command;
        std::string _name_of_pizz;
        int _number_of_pizz;
    protected:
    private:

};

#endif /* !RECEPTION_HPP_ */
