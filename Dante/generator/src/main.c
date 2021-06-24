/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator/solver labyrinthe by Theo and Guillaume
*/

#include "../lib/my/my.h"

void finish(generator_t *gen, int i)
{
    for (; gen->line != gen->y; gen->line++){
        for (; i != gen->x; i++)
            gen->map[gen->line - 1][i] = '*';
    }
}

int print_map(generator_t *gen)
{
    for (int i = 0; i != gen->y; i++) {
        printf("%s", gen->map[i]);
        if (i + 1 != gen->y)
            printf("\n");
    }
    return (0);
}

void do_free(generator_t *gen)
{
    for (int i = 0; i != gen->y; i++)
        free(gen->map[i]);
    free(gen->map);
    free(gen);
}

int main(int ac, char **av)
{
    generator_t *gen = malloc(sizeof(generator_t));

    if (error_handling(ac, av) == 84)
        return (84);
    srand(time(NULL));
    gen->x = my_getnbr(av[1]);
    gen->y = my_getnbr(av[2]);
    if (my_getnbr(av[1]) >= my_getnbr(av[2]))
        gen->max_lenght = my_getnbr(av[1]);
    if (my_getnbr(av[1]) < my_getnbr(av[2]))
        gen->max_lenght = my_getnbr(av[2]);
    if (create_map(gen) == 84)
        return (84);
    if (ac == 4)
        generate_perfect(gen);
    print_map(gen);
    do_free(gen);
    return (0);
}