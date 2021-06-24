/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** bsq
*/

#include "include/my.h"
#include "include/struct.h"

void replace(bsq_t *bsq)
{
    for (; bsq->buf[bsq->i] != '\0'; bsq->i++) {
        if (bsq->buf[bsq->i] == 'o')
            bsq->buf[bsq->i] = '0';
        else if (bsq->buf[bsq->i] == '\n');
        else if (bsq->i < bsq->count_line || bsq->buf[bsq->i - 1] == '\n')
            bsq->buf[bsq->i] = '1';
        else
            square(bsq);
    }
}

void square(bsq_t *bsq)
{
    bsq->left = bsq->buf[bsq->i - 1];
    bsq->up = bsq->buf[bsq->i - bsq->count_line];
    bsq->up_left = bsq->buf[bsq->i - bsq->count_line - 1];

    if (bsq->left <= bsq->up && bsq->left <= bsq->up_left)
        bsq->buf[bsq->i] = bsq->left + 1;
    else if (bsq->up <= bsq->left && bsq->up <= bsq->up_left)
            bsq->buf[bsq->i] = bsq->up + 1;
    else
        bsq ->buf[bsq->i] = bsq->up_left + 1;
    find_pos(bsq);
}

void find_pos(bsq_t *bsq)
{
    if (bsq->biggest_square < bsq->buf[bsq->i] - 48) {
        bsq->biggest_square = bsq->buf[bsq->i] - 48;
        bsq->position = bsq->i;
    }
}

void replace_x(bsq_t *bsq)
{
    for (int x = 0; x < bsq->biggest_square; x++) {
        for (int y = 0; y < bsq->biggest_square; y++) {
            bsq->buf[bsq->position] = 'x';
            bsq->position--;
        }
        bsq->position = bsq->position - bsq->count_line + bsq->biggest_square;
    }
    replace2(bsq);
    my_putstr(bsq->buf);
}

void replace2(bsq_t *bsq)
{
    for (int f = 0; bsq->buf[f] != '\0'; f++) {
        if (bsq->buf[f] >= '1' && bsq->buf[f] <= '9')
            bsq->buf[f] = '.';
        if (bsq->buf[f] == '0')
            bsq->buf[f] = 'o';
    }
}