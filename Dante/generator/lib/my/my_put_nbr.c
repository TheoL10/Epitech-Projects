/*
** EPITECH PROJECT, 2020
** put nbr
** File description:
** voila
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int d = 1;
    if ( nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while (( nb / d) >= 10 )
        d = d*10;
    while (d > 0) {
        my_putchar(( nb / d) % 10 + '0');
        d = d / 10;
    }
}
