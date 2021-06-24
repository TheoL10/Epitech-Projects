/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator/solver labyrinthe by Theo and Guillaume
*/

#include "../lib/my/my.h"

int error_handling(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (84);
    if (my_getnbr(av[1]) <= 0)
        return (84);
    if (my_getnbr(av[2]) <= 0)
        return (84);
    if (ac == 4 && strcmp(av[3], "perfect") != 0)
        return (84);
    return (0);
}