/*
** EPITECH PROJECT, 2021
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct solver_s
{
    char **buffer;
    char *map;
    int x_max;
    int y_max;
    int size;
    int x;
    int y;
    int count;
} solver_t;

#endif
