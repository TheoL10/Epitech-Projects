/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** task05 day05
*/

#include <unistd.h>

int  my_compute_square_root(int nb)
{
    int i = 0;

    if (0 <= nb <= 2147483647)
        for (; i != nb ; i++){
            if (i * i == nb)
                return (i);
        }
    if (i * i != nb)
        return (0);
}
