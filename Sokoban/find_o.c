/*
** EPITECH PROJECT, 2021
** find_o
** File description:
** find_o
*/

#include "include/my.h"
#include "include/struct.h"

void error2(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->buf[i] != '\0'; i++) {
        if (sokoban->buf[i] == 'O')
            sokoban->count_o++;
        if (sokoban->buf[i] == 'X')
            sokoban->count_x++;
    }
    if (sokoban->count_o != sokoban->count_x) {
        sokoban->count2 = 1;
        sokoban->condition_return = 2;
    }
}