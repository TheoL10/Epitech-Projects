/*
** EPITECH PROJECT, 2020
** my_bracket
** File description:
** my_bracket
*/

#include "../include/my.h"

int my_atoi(char **str)
{
    int i;

    i = 0;
    while (**str >= '0' && **str <= '9') {
        i = i * 10 + (**str - '0');
        (*str)++;
    }
    return (i);
}