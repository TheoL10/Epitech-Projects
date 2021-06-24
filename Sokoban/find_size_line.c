/*
** EPITECH PROJECT, 2021
** find_size_line
** File description:
** find_size_line
*/

#include "include/my.h"
#include "include/struct.h"

void find_size_line(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->buf[i] != '\n'; i++)
        sokoban->size_l = i + 2;
}