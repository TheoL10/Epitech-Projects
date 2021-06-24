/*
** EPITECH PROJECT, 2021
** generator
** File description:
** generator
*/

#include "../lib/my/my.h"

void move_right_down(generator_t *gen, int i)
{
    i++;
    gen->map[gen->line][i] = '*';
    i++;
    gen->map[gen->line][i] = '*';
    move_down(gen, i);
}

void move_up(generator_t *gen, int i)
{
    for (; gen->line - 1 != 0; gen->line--)
        gen->map[gen->line - 1][i] = '*';
    move_right_down(gen, i);
}

void move_right_up(generator_t *gen, int i)
{
    i++;
    gen->map[gen->line - 1][i] = '*';
    i++;
    gen->map[gen->line - 1][i] = '*';
    move_up(gen, i);
}

void move_down(generator_t *gen, int i)
{
    for (; gen->line != gen->y - 1; gen->line++)
        gen->map[gen->line][i] = '*';
    if (i < gen->x - 4)
        move_right_up(gen, i);
    else
        finish(gen, i);
}

void resolve(generator_t *gen)
{
    int i = 0;
    gen->line = 0;

    while (i != gen->x && gen->line != gen->y)
        move_down(gen, i);
}