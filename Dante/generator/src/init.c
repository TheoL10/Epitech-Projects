/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator/solver labyrinthe by Theo and Guillaume
*/

#include "../lib/my/my.h"

int init_struct(generator_t *gen, int x, int y)
{
    if (malloc_maze(gen, x, y) == 84)
        return (84);
    gen->x_max = x;
    gen->y_max = y;
    gen->output = 0;
    return (0);
}