/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "struct.h"

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
void my_printf_str(va_list *ap);
void my_printf_char(va_list *ap);
void my_printf_nbr(va_list *ap);
void find_index(char f, va_list *ap);
void my_printf(char *src, ...);
int my_put_unsigned_nbr(unsigned int nb);
void my_printf_unsigned_nbr(va_list *ap);
void my_printf_pourcent(va_list *ap);
void my_printf_oct_nbr(va_list *ap);
int my_put_oct_nbr(unsigned int nb);
void my_printf_hexa_nbr(va_list *ap);
int my_put_hexa_nbr(unsigned int nb);
int my_put_hexamaj_nbr(unsigned int nb);
void my_printf_hexamaj_nbr(va_list *ap);
int my_put_bin_nbr(int nb);
void my_printf_bin_nbr(va_list *ap);
void my_printf_strmaj(va_list *ap);
int my_put_hexa2_nbr(unsigned int nb);
void my_printf_hexa2_nbr(va_list *ap);

#endif
