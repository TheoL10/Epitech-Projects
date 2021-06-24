/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator/solver labyrinthe by Theo and Guillaume
*/

#include "../lib/my/my.h"
#include "../lib/my/struct.h"

void h_lines_colums(solver_t *solv)
{
    for (; solv->buffer[0][solv->x_max] != '\0'; solv->x_max++);
    for (; solv->buffer[solv->y_max] != NULL; solv->y_max++);
}

int find_solution(solver_t *solv, int y, int x)
{
    if (x == solv->x_max - 1 && y == solv->y_max - 1) {
        solv->buffer[y][x] = 'o';
        return (1);
    }
    if (x >= 0 && y >= 0 && x < solv->x_max &&
        y < solv->y_max && solv->buffer[y][x] == '*') {
        solv->buffer[y][x] = 'o';
        if (find_solution(solv, y, x + 1))
            return (1);
        if (find_solution(solv, y + 1, x))
            return (1);
        if (find_solution(solv, y - 1, x))
            return (1);
        if (find_solution(solv, y, x - 1))
            return (1);
        solv->buffer[y][x] = '*';
    }
    return (0);
}

void print_buf(solver_t *solv)
{
    for (int i = 0; solv->buffer[i] != NULL; i++) {
        printf("%s", solv->buffer[i]);
        if (solv->buffer[i + 1] != NULL)
            printf("\n");
    }
}