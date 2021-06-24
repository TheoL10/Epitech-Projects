/*
** EPITECH PROJECT, 2020
** my_put_hexa2_nbr
** File description:
** my_put_hexa2_nbr
*/

#include "../../include/my.h"
#include "../../include/struct.h"

int my_put_hexa2_nbr(unsigned int nb)
{
    char result[100];
    int i = 0;
    char *hexa = "0123456789abcdef";

    for (; nb != '\0'; i++) {
        result[i] = hexa[nb % my_strlen(hexa)];
        nb = nb / my_strlen(hexa);
    }
    result[i] = '\0';
    my_putstr("0x");
    my_putstr(my_revstr(result));
    return (0);
}