/*
** EPITECH PROJECT, 2022
** time_gestion
** File description:
** time_gestion
*/

#ifndef TIMEGESTION_HPP_
#define TIMEGESTION_HPP_
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

class TimeGestion {
    public:
        TimeGestion();
        ~TimeGestion();
        int time(void);
    protected:
    private:
};

#endif
