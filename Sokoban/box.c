/*
** EPITECH PROJECT, 2021
** box
** File description:
** box
*/

#include "include/my.h"
#include "include/struct.h"

void box_error(sokoban_t *sokoban)
{
    int oui = 0;
    sokoban->count_loose = 0;

    for (int i = 0; sokoban->buf[i] != '\0'; i++) {
        if ((sokoban->buf[i] == 'X' && sokoban->buf[i + 1] == '#')
        || (sokoban->buf[i] == 'X' && sokoban->buf[i + 1] == 'X')
        || (sokoban->buf[i] == 'X' && sokoban->buf[i - 1] == '#')
        || (sokoban->buf[i] == 'X' && sokoban->buf[i - 1] == 'X'))
            oui++;
        if ((sokoban->buf[i] == 'X' && sokoban->buf[i + sokoban->size_l] == '#')
        || (sokoban->buf[i] == 'X' && sokoban->buf[i + sokoban->size_l] == 'X')
        || (sokoban->buf[i] == 'X' && sokoban->buf[i - sokoban->size_l] == '#')
        || (sokoban->buf[i] == 'X' && sokoban->buf[i - sokoban->size_l] == 'X'))
            oui++;
        if (oui == 2)
            sokoban->count_loose++;
        oui = 0;
    }
}

void box_left(sokoban_t *sokoban)
{
    if (sokoban->buf[sokoban->pos_p - 1] == 'X') {
        if (sokoban->buf[sokoban->pos_p - 2] != '#'
            && sokoban->buf[sokoban->pos_p - 2] != 'X') {
            sokoban->buf[sokoban->pos_p - 1] = 'P';
            sokoban->buf[sokoban->pos_p - 2] = 'X';
        if (sokoban->reset[sokoban->pos_p] == 'O') {
            sokoban->buf[sokoban->pos_p] = 'O';
            sokoban->count_win--;
        }
        else
            sokoban->buf[sokoban->pos_p] = ' ';
        }
    }
}

void box_right(sokoban_t *sokoban)
{
    if (sokoban->buf[sokoban->pos_p + 1] == 'X') {
        if (sokoban->buf[sokoban->pos_p + 2] != '#'
            && sokoban->buf[sokoban->pos_p + 2] != 'X') {
            sokoban->buf[sokoban->pos_p + 1] = 'P';
            sokoban->buf[sokoban->pos_p + 2] = 'X';
        if (sokoban->reset[sokoban->pos_p] == 'O') {
            sokoban->buf[sokoban->pos_p] = 'O';
            sokoban->count_win--;
        }
        else
            sokoban->buf[sokoban->pos_p] = ' ';
        }
    }
}

void box_down(sokoban_t *sokoban)
{
    if (sokoban->buf[sokoban->pos_p + sokoban->size_l] == 'X') {
        if (sokoban->buf[sokoban->pos_p + (sokoban->size_l * 2)] != '#'
            && sokoban->buf[sokoban->pos_p + (sokoban->size_l * 2)] != 'X') {
            sokoban->buf[sokoban->pos_p + sokoban->size_l] = 'P';
            sokoban->buf[sokoban->pos_p + (sokoban->size_l * 2)] = 'X';
        if (sokoban->reset[sokoban->pos_p] == 'O') {
            sokoban->buf[sokoban->pos_p] = 'O';
            sokoban->count_win--;
        }
        else
            sokoban->buf[sokoban->pos_p] = ' ';
        }
    }
}

void box_up(sokoban_t *sokoban)
{
    if (sokoban->buf[sokoban->pos_p - sokoban->size_l] == 'X') {
        if (sokoban->buf[sokoban->pos_p - (sokoban->size_l * 2)] != '#'
            && sokoban->buf[sokoban->pos_p - (sokoban->size_l * 2)] != 'X') {
            sokoban->buf[sokoban->pos_p - sokoban->size_l] = 'P';
            sokoban->buf[sokoban->pos_p - (sokoban->size_l * 2)] = 'X';
        if (sokoban->reset[sokoban->pos_p] == 'O') {
            sokoban->buf[sokoban->pos_p] = 'O';
            sokoban->count_win--;
        }
        else
            sokoban->buf[sokoban->pos_p] = ' ';
        }
    }
}