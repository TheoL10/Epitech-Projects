/*
** EPITECH PROJECT, 2021
** save
** File description:
** save
*/

#include "include/my.h"
#include "include/struct.h"

void save(sokoban_t *sokoban)
{
    if (sokoban->condition == 32)
        my_strcpy(sokoban->buf, sokoban->reset);
}