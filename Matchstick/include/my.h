/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
void print_map(match_t *match, int arg);
void first_line(match_t *match);
void mid_map(match_t *match, int arg, int number, int jump);
void last_line(match_t *match, int result);
void how_lines(match_t *match);
void print_buf(match_t *match, int arg);
void ia_remove_stick(match_t *match);
int remove_stick(match_t *match, int arg2, int arg);
int remove_stick2(match_t *match);
int remove_stick3(match_t *match, int arg, int arg2);
int remove_stick4(match_t *match, int arg, int arg2);
void remove_stick5(match_t *match, int arg, int arg2);
void test(match_t *match, int arg, int arg2);
void error(match_t *match, int arg, int arg2);

#endif