/*
** EPITECH PROJECT, 2022
** time_gestion
** File description:
** time_gestion
*/

#include "hpp/time_gestion.hpp"
#include <chrono>
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
#include "hpp/Pizza.hpp"

TimeGestion::TimeGestion()
{

}

TimeGestion::~TimeGestion()
{
}

int TimeGestion::time(void)
{
    std::chrono::steady_clock::time_point time_now = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point time_end = time_now + std::chrono::seconds(4);

    while (1) {
        time_now = std::chrono::steady_clock::now();
        if (time_now >= time_end)
            break;
    }
    return (0);
}