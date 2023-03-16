/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** cook_pizza
*/

#include "hpp/Kitchen.hpp"

std::mutex cout_guard;

void Kitchen::prep_margarita()
{
    while (_fridge->_retrieve_ingredients("Margarita") != 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    int time_sleep = 1 * _cooking_multiplier;
    std::this_thread::sleep_for(std::chrono::seconds(time_sleep));
    std::unique_lock<std::mutex> guard(cout_guard); // doe, tomato, gruyere
    std::cout << "\nHere is your margarita " << std::endl;
}

void Kitchen::cook_margarita(Kitchen *kitchen, int number_of_pizz)
{
    std::function<void(void)> f = std::bind(&Kitchen::prep_margarita, kitchen);
    for (auto i = 1; i <= number_of_pizz; i++)
        kitchen->exec_func(f);
}

void Kitchen::prep_regina()
{
    while (_fridge->_retrieve_ingredients("Regina") != 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    int time_sleep = 2 * _cooking_multiplier;
    std::this_thread::sleep_for(std::chrono::seconds(time_sleep));
    std::unique_lock<std::mutex> guard(cout_guard); //doe, tomato, gruyere, ham, mushrooms
    std::cout << "\nHere is your regina" << std::endl;
}

void Kitchen::cook_regina(Kitchen *kitchen, int number_of_pizz)
{
    std::function<void(void)> f = std::bind(&Kitchen::prep_regina, kitchen);
    for (auto i = 1; i <= number_of_pizz; i++)
        kitchen->exec_func(f);
}

void Kitchen::prep_americana()
{
    while (_fridge->_retrieve_ingredients("Americana") != 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    int time_sleep = 2 * _cooking_multiplier;
    std::this_thread::sleep_for(std::chrono::seconds(time_sleep));
    std::unique_lock<std::mutex> guard(cout_guard); // doe, tomato, gruyere, steak
    std::cout << "\nHere is your americana" << std::endl;
}

void Kitchen::cook_americana(Kitchen *kitchen, int number_of_pizz)
{
    std::function<void(void)> f = std::bind(&Kitchen::prep_americana, kitchen);
    for (auto i = 1; i <= number_of_pizz; i++)
        kitchen->exec_func(f);
}

void Kitchen::prep_fantasia()
{
    while (_fridge->_retrieve_ingredients("Fantasia") != 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    int time_sleep = 4 * _cooking_multiplier;
    std::this_thread::sleep_for(std::chrono::seconds(time_sleep));
    std::unique_lock<std::mutex> guard(cout_guard); // doe, tomato, eggplant, goat cheese, chief love
    std::cout << "\nHere is your fantasia" << std::endl;
}

void Kitchen::cook_fantasia(Kitchen *kitchen, int number_of_pizz)
{
    std::function<void(void)> f = std::bind(&Kitchen::prep_fantasia, kitchen);
    for (auto i = 1; i <= number_of_pizz; i++)
        kitchen->exec_func(f);
}