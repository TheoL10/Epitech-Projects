/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** task02
*/
#include<unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    while (*str != 0)
    {
        my_putchar(*str);
        str++;
    }
}
