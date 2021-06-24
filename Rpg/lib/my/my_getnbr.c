/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int c = 0;
    int i = 0;
    int j = 1;

    while (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-')
            j = j * (-1);
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        c = (c * 10) + str[i] - '0';
        i++;
        }
    return (c * j);
}