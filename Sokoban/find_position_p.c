/*
** EPITECH PROJECT, 2021
** find_position
** File description:
** find_position
*/

#include "include/my.h"
#include "include/struct.h"

void find_position_p(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->buf[i] != 'P'; i++)
        sokoban->pos_p = i + 1;
}