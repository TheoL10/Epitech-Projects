/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/

#include "../lib/my/my.h"

void soluce_maze(generator_t *gen, int i)
{
    int o = rand() % gen->x;

    if (o > gen->x / 3)
        gen->map[gen->line][i] = 'X';
    else if (o <= gen->x / 2)
        gen->map[gen->line][i] = '*';
}

int create_maze(generator_t *gen)
{
    for (int i = 0; i != gen->x; i++) {
        if (gen->line == 0 && i == 0)
            gen->map[0][i] = '*';
        else if (gen->line == gen->y - 1 && i == gen->x - 1)
            gen->map[gen->line][i] = '*';
        else
            soluce_maze(gen, i);
    }
    return (0);
}

int create_map(generator_t *gen)
{
    if ((gen->map = malloc(sizeof(char *) * (gen->max_lenght))) == NULL)
        return (84);
    for (gen->line = 0; gen->line != gen->y; gen->line++) {
        if ((gen->map[gen->line] = malloc(sizeof(char) * (gen->max_lenght + 1))) == NULL)
            return (84);
        create_maze(gen);
        gen->map[gen->line][gen->x] = '\0';
    }
    resolve(gen);
    return (0);
}