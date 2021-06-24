/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "my.h"
#include <stdarg.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

typedef struct ls_s
{
    DIR *dir;
    char *buffer;
    int size;
    DIR *dir2;
} ls_t;

void my_ls(ls_t *ls);
void my_ls2(DIR *directories);
void my_lsa(ls_t *ls);
void my_lsa2(DIR *directories);
void my_lsd(void);
void display_error(char **argv);
void init_struct(ls_t *ls);
void my_2(int argc, char **argv);

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

#endif
