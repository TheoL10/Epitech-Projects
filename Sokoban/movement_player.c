/*
** EPITECH PROJECT, 2021
** movement_player
** File description:
** movement_player
*/

#include "include/my.h"
#include "include/struct.h"

void move_left(sokoban_t *sokoban)
{
    if (sokoban->buf[sokoban->pos_p - 1] != '#'
        && sokoban->buf[sokoban->pos_p - 1] != 'X') {
        sokoban->buf[sokoban->pos_p - 1] = 'P';
        if (sokoban->reset[sokoban->pos_p] == 'O') {
            sokoban->buf[sokoban->pos_p] = 'O';
            sokoban->count_win--;
        }
        else
            sokoban->buf[sokoban->pos_p] = ' ';
    }
    box_left(sokoban);
}

void move_right(sokoban_t *sokoban)
{
    if (sokoban->buf[sokoban->pos_p + 1] != '#'
        && sokoban->buf[sokoban->pos_p + 1] != 'X') {
        sokoban->buf[sokoban->pos_p + 1] = 'P';
        if (sokoban->reset[sokoban->pos_p] == 'O') {
            sokoban->buf[sokoban->pos_p] = 'O';
            sokoban->count_win--;
        }
        else
            sokoban->buf[sokoban->pos_p] = ' ';
    }
    box_right(sokoban);
}

void move_down(sokoban_t *sokoban)
{
    if (sokoban->buf[sokoban->pos_p + sokoban->size_l] != '#'
        && sokoban->buf[sokoban->pos_p + sokoban->size_l] != 'X') {
        sokoban->buf[sokoban->pos_p + sokoban->size_l] = 'P';
        if (sokoban->reset[sokoban->pos_p] == 'O') {
            sokoban->buf[sokoban->pos_p] = 'O';
            sokoban->count_win--;
        }
        else
            sokoban->buf[sokoban->pos_p] = ' ';
    }
    box_down(sokoban);
}

void move_up(sokoban_t *sokoban)
{
    if (sokoban->buf[sokoban->pos_p - sokoban->size_l] != '#'
        && sokoban->buf[sokoban->pos_p - sokoban->size_l] != 'X') {
        sokoban->buf[sokoban->pos_p - sokoban->size_l] = 'P';
        if (sokoban->reset[sokoban->pos_p] == 'O') {
            sokoban->buf[sokoban->pos_p] = 'O';
            sokoban->count_win--;
        }
        else
            sokoban->buf[sokoban->pos_p] = ' ';
    }
    box_up(sokoban);
}

int movement_player(sokoban_t *sokoban)
{
    if (sokoban->condition == KEY_LEFT) {
        if (sokoban->buf[sokoban->pos_p - 1] == 'X'
        && sokoban->buf[sokoban->pos_p - 2] == 'O')
        sokoban->count_win++;
        move_left(sokoban);
    }
    if (sokoban->condition == KEY_RIGHT) {
        if (sokoban->buf[sokoban->pos_p + 1] == 'X'
        && sokoban->buf[sokoban->pos_p + 2] == 'O')
        sokoban->count_win++;
        move_right(sokoban);
    }
    movement_player2(sokoban);
    save(sokoban);
    clear();
    printw(sokoban->buf);
    condition_win(sokoban);
    box_error(sokoban);
    condition_loose(sokoban);
    return (0);
}