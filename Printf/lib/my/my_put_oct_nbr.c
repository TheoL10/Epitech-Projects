/*
** EPITECH PROJECT, 2020
** my_put_oct_nbr
** File description:
** my_put_oct_nbr
*/

#include "../../include/my.h"
#include "../../include/struct.h"

int my_put_oct_nbr(unsigned int nb)
{
    char result[100];
    int i = 0;
    char *oct = "01234567";

    for (; nb != '\0'; i++) {
        result[i] =  oct[nb % my_strlen(oct)];
        nb = nb / my_strlen(oct);
    }
    result[i] = '\0';
    my_putstr(my_revstr(result));
    return (0);
}