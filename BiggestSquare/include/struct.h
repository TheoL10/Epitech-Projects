/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct bsq_s
{
    char *buf;
    int o;
    int file;
    int size;
    int count_line;
    int left;
    int up_left;
    int up;
    int count;
    int i;
    int position;
    int biggest_square;
} bsq_t;

#endif
