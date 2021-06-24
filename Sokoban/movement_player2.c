/*
** EPITECH PROJECT, 2021
** movement_player2
** File description:
** movement_player2
*/

#include "include/my.h"
#include "include/struct.h"

void movement_player2(sokoban_t *sokoban)
{
    if (sokoban->condition == KEY_DOWN) {
        if (sokoban->buf[sokoban->pos_p + sokoban->size_l] == 'X'
        && sokoban->buf[sokoban->pos_p + (sokoban->size_l * 2)] == 'O')
        sokoban->count_win++;
        move_down(sokoban);
    }
    if (sokoban->condition == KEY_UP) {
        if (sokoban->buf[sokoban->pos_p - sokoban->size_l] == 'X'
        && sokoban->buf[sokoban->pos_p - (sokoban->size_l * 2)] == 'O')
        sokoban->count_win++;
        move_up(sokoban);
    }
}