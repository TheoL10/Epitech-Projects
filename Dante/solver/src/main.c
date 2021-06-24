/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator/solver labyrinthe by Theo and Guillaume
*/

#include "../lib/my/my.h"
#include "../lib/my/struct.h"

int main(int ac, char **av)
{
    solver_t *solv = malloc(sizeof(solver_t));

    if (ac != 2)
        return (84);
    if (read_map(solv, av) == 84)
        return (84);
    solv->buffer = my_str_to_wordtab(solv->map, '\n');
    h_lines_colums(solv);
    error_gestion(solv);
    if (solv->count == 1)
        return (0);
    if (find_solution(solv, 0, 0) && solv->count == 0)
        print_buf(solv);
    else
        printf("no solution found");
    return (0);
}