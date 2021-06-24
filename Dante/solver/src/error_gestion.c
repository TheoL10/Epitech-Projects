/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator/solver labyrinthe by Theo and Guillaume
*/

#include "../lib/my/my.h"
#include "../lib/my/struct.h"

int error_gestion(solver_t *solv)
{
    if (solv->buffer[solv->y_max - 1][solv->x_max - 1] == 'X') {
        printf("no solution found");
        solv->count = 1;
    }
    return (0);
}