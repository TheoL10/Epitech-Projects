/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator/solver labyrinthe by Theo and Guillaume
*/

#include "../lib/my/my.h"

int generate_perfect(generator_t *gen)
{
    for (int i = 0; i < gen->y; i++) {
        gen->north = 0;
        gen->west = 0;
        for (int j = 0; j < gen->x; j++) {
            if (i == 0 || j == (gen->x - 1))
                gen->map[i][j] = '*';
            else
                gen->map[i][j] = 'X';
        }
    }
    return (0);
}