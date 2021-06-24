/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void find_index(char f, va_list *ap)
{
    for (int j = 0; tableau[j].flag != 0; j++) {
        if (tableau[j].flag == f)
            tableau[j].str(ap);
    }
}

void my_printf(char *src, ...)
{
    va_list ap;

    va_start(ap, src);
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == '%') {
            find_index(src[i + 1], &ap);
            i++;
        }
        else
            write(1, &src[i], 1);
    }
    va_end(ap);
}