/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"

int get_line(bsq_t *bsq)
{
    for (int i = 0; bsq->buf[i] != '\n'; i++) {
        bsq->count++;
    }
    bsq->count++;
    printf("%d\n", bsq->count);
    return (bsq->count);
}

int main(int ac, char **av)
{
    bsq_t *bsq = malloc(sizeof(bsq_t));
    struct stat buffer;

    if (ac != 2)
        return (84);
    bsq->o = open(av[1], O_RDONLY);
    stat(av[1], &buffer);
    bsq->size = buffer.st_size;
    if (bsq->size == 0) {
        write(2, "Empty map\n", 10);
        return (84);
    }
    bsq->buf = malloc((sizeof(char) * (bsq->size + 1)));
    bsq->file = read(bsq->o, bsq->buf, bsq->size);
    while ((*bsq->buf >= '0' && *bsq->buf <= '9') || *bsq->buf == '\n')
        bsq->buf++;
    bsq->count_line = get_line(bsq);
    replace(bsq);
    replace_x(bsq);
    close(bsq->o);
}