/*
** EPITECH PROJECT, 2020
** my_get_nbr
** File description:
** my_get_nbr
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int nb = 0;
    int m = 0;
    int k = 0;

    for (; str[k] == '-' || str[k] == '+'; k++) {
        if (str[k] == '-')
            m++;
    }
    for (; str[k] >= '0' && str[k] <= '9'; k++)
        nb = nb * 10 + str[k] - 48;
    for (int j = 0; j != m; j++)
        nb = nb * (-1);
    return (nb);
}