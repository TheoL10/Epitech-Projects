/*
** EPITECH PROJECT, 2021
** condition_loose.c
** File description:
** condition_loose
*/

#include "include/my.h"
#include "include/struct.h"

void find_box(sokoban_t *sokoban)
{
    for (int i = 1; sokoban->buf[i] != '\0'; i++)
        if (sokoban->buf[i] == 'X')
            sokoban->count_box++;
}

void condition_loose(sokoban_t *sokoban)
{
    if (sokoban->count_box == sokoban->count_loose) {
        sokoban->condition_return = 0;
        sokoban->count2 = 1;
    }
}