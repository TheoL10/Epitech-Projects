/*
** EPITECH PROJECT, 2020
** my_put_bin_nbr
** File description:
** my_put_bin_nbr
*/

#include "../../include/my.h"
#include "../../include/struct.h"

int my_put_bin_nbr(int nb)
{
    char result[100];
    int i = 0;
    char *bin = "01";

    for (; nb != '\0'; i++) {
        result[i] = bin[nb % my_strlen(bin)];
        nb = nb / my_strlen(bin);
    }
    result[i] = '\0';
    my_putstr(my_revstr(result));
    return (0);
}