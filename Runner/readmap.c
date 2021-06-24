/*
** EPITECH PROJECT, 2020
** readmap
** File description:
** readmap
*/

#include "include/my.h"
#include "include/struct.h"

void readmap(runner_t *run, char **argv)
{
    struct stat buffer;

    run->o = open(argv[1], O_RDONLY);
    stat(argv[1], &buffer);
    run->size = buffer.st_size;
    run->buf = malloc((sizeof(char) * (run->size + 1)));
    run->file = read(run->o, run->buf, run->size);
    rectangle(run);
}