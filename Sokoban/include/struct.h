/*
** EPITECH PROJECT, 2021
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "my.h"

typedef struct sokoban_s
{
    char *buf;
    int file;
    int size;
    int condition;
    int pos_p;
    int size_l;
    int count;
    int count_o;
    int count_x;
    char *reset;
    int count2;
    int count_win;
    int count_p;
    char *str_pos_o;
    char *str_pos_x;
    int count_win_x;
    int condition_return;
    int count_box;
    int count_loose;
    int test;
} sokoban_t;

typedef struct print_s
{
    char flag;
    void (*str) (va_list *ap);
} print_t;

static const print_t tableau[] = {
    {'s', &my_printf_str},
    {'c', &my_printf_char},
    {'d', &my_printf_nbr},
    {'i', &my_printf_nbr},
    {'u', &my_printf_unsigned_nbr},
    {'%', &my_printf_pourcent},
    {'o', &my_printf_oct_nbr},
    {'x', &my_printf_hexa_nbr},
    {'X', &my_printf_hexamaj_nbr},
    {'b', &my_printf_bin_nbr},
    {'p', &my_printf_hexa2_nbr},
    {'\0', NULL}
};

void box_error(sokoban_t *sokoban);
void box_left(sokoban_t *sokoban);
void box_right(sokoban_t *sokoban);
void box_down(sokoban_t *sokoban);
void box_up(sokoban_t *sokoban);
void save(sokoban_t *sokoban);
int movement_player(sokoban_t *sokoban);
void find_size_line(sokoban_t *sokoban);
void find_position_p(sokoban_t *sokoban);
void error2(sokoban_t *sokoban);
void condition_win(sokoban_t *sokoban);
void find_p(sokoban_t *sokoban);
void movement_player2(sokoban_t *sokoban);
void move_down(sokoban_t *sokoban);
void move_up(sokoban_t *sokoban);
void condition_loose(sokoban_t *sokoban);
void find_box(sokoban_t *sokoban);

#endif
