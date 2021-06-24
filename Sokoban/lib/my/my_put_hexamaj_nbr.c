/*
** EPITECH PROJECT, 2020
** my_put_hexamaj_nbr
** File description:
** my_put_hexamaj_nbr
*/

#include "../../include/my.h"
#include "../../include/struct.h"

int my_put_hexamaj_nbr(unsigned int nb)
{
    char result[100];
    int i = 0;
    char *hexamaj = "0123456789ABCDEF";

    for (; nb != '\0'; i++) {
        result[i] = hexamaj[nb % my_strlen(hexamaj)];
        nb = nb / my_strlen(hexamaj);
    }
    result[i] = '\0';
    my_putstr(my_revstr(result));
    return (0);
}