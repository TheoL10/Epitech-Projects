/*
** EPITECH PROJECT, 2021
** dante
** File description:
** generator/solver labyrinthe by Theo and Guillaume
*/

#include "../lib/my/my.h"
#include "../lib/my/struct.h"

int read_map(solver_t *solv, char **av)
{
    struct stat buffer;
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (84);
    stat(av[1], &buffer);
    solv->size = buffer.st_size;
    if (solv->size <= 0)
        return (84);
    solv->map = malloc(sizeof(char) * (solv->size + 1));
    if (solv->map == NULL)
        return (84);
    if (read(fd, solv->map, solv->size + 1) == -1)
        return (84);
    return (0);
}