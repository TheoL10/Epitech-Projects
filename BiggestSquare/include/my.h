/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/


#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "struct.h"

void my_putchar(char c);
int my_putstr(char const *str);
void square(bsq_t *bsq);
void find_pos(bsq_t *bsq);
void replace2(bsq_t *bsq);
void replace_x(bsq_t *bsq);
void replace(bsq_t *bsq);

#endif
