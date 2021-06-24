/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct n4s_s
{
    int left;
    int right;
    char **pos;
    float rayon[32];
}n4s_t;

void move_right(n4s_t *n4s, size_t size, char *buffer);
int print_command(char *str, size_t size, char *buffer);

#endif