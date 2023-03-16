/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** error_handling
*/

#include "hpp/error_handling.hpp"

Error::Error(void)
{
}

Error::~Error(void)
{
}

// ERROR HANDLING ///////////////////////////////////////////////////////////////////////////////////////////////
int Error::show_usage(void)
{
    std::cout << "Usage: ./plazza [cooking_time_multiplier] [cooks_per_kitchen] [time_to_replace_ingredients]" << std::endl;
    return (84);
}

int Error::check_numbers(char *a, char *b, char *c)
{
    if (atoi(a) > 0 && atoi(b) > 0 && atoi(c) > 0)
        return (0);
    else
        return (show_usage());
}

int Error::error_handling(int argc, char **argv)
{
    if (argc != 4) {
        return (show_usage());
    }
    return (check_numbers(argv[1], argv[2], argv[3]));
}
// ERROR HANDLING ///////////////////////////////////////////////////////////////////////////////////////////////