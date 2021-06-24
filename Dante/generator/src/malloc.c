/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator/solver labyrinthe by Theo and Guillaume
*/

#include "../lib/my/my.h"

int malloc_maze(generator_t *gen, int x, int y)
{
    if ((gen->map = malloc(sizeof(char *) * (y + 1))) == NULL)
        return (84);
    for (int i = 0; i < y; i++)
        if ((gen->map[i] = malloc(sizeof(char) * (x + 1))) == NULL)
            return (84);
    return (0);
}