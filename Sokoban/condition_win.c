/*
** EPITECH PROJECT, 2021
** condition_win
** File description:
** condition_win
*/

#include "include/my.h"
#include "include/struct.h"

void condition_win(sokoban_t *sokoban)
{
    if (sokoban->count_o == sokoban->count_win) {
        sokoban->condition_return = 1;
        sokoban->count2 = 1;
    }
}