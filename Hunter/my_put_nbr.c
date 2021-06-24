/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** task7
*/

#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    long z = nb;

    if (z < 0) {
        my_putchar('-');
        z = z * (-1);
    }
    if (z >= 10)
        my_put_nbr(z / 10);
    my_putchar((z % 10) + 48);
    return (0);
}
