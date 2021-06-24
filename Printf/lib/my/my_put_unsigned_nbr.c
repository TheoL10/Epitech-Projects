/*
** EPITECH PROJECT, 2020
** my_put_unsigned_nbr
** File description:
** my_put_unsigned_nbr
*/

#include "../../include/my.h"
#include "../../include/my.h"

int my_put_unsigned_nbr(unsigned int nb)
{
    long z = nb;

    if (z < 0) {
        my_putchar('-');
        z = z * (-1);
    }
    if (z >= 10)
        my_put_unsigned_nbr(z / 10);
    my_putchar((z % 10) + 48);
    return (0);
}