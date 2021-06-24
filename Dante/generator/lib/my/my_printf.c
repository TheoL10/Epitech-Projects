/*
** EPITECH PROJECT, 2020
** printff
** File description:
** printff
*/

#include "my.h"

void finder_fonction(va_list *arg, char specifier)
{
    int count = 0;

    for (int tmp = 0; spe[tmp].coco != '\0'; tmp++) {
        if (spe[tmp].coco == specifier) {
            spe[tmp].functiontab(arg);
            count = 1;
        }
    }
    if (count == 0 && specifier != '%') {
        my_putchar('%');
        my_putchar(specifier);
    }
}

int my_printf(char *sentence, ...)
{
    va_list arg;
    int var = 0;

    va_start(arg, sentence);
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == '%' && sentence[i + 1] != '%') {
            finder_fonction(&arg, sentence[i + 1]);
            i++;
        } if (sentence[i] == '%' && sentence[i + 1] == '%') {
            my_putchar('%');
            i++;
            var = 1;
        } if (sentence[i] != '%' && sentence[i - 1] != '%') {
            my_putchar(sentence[i]);
        } if (sentence[i] != '%' && var == 1) {
            my_putchar(sentence[i]);
            var = 0;
        }
    } va_end(arg);
    return (0);
}