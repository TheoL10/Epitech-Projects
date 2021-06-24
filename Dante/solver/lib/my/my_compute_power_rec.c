/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** task04
*/

#include <unistd.h>

int  my_compute_power_rec(int nb , int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    else{
        int result = nb * my_compute_power_rec(nb , p - 1);
        if (p == 1){
            if (1 <= result < 2147483647)
                return (result);
            else
                return (0);
        }
    }
}
