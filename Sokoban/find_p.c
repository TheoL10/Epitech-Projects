/*
** EPITECH PROJECT, 2021
** find_p
** File description:
** find_p
*/

#include "include/my.h"
#include "include/struct.h"

void find_p(sokoban_t *sokoban)
{
    for (int i = 1; sokoban->buf[i] != '\0'; i++)
        if (sokoban->buf[i] == 'P')
            sokoban->count_p++;
}