/*
** EPITECH PROJECT, 2020
** printff
** File description:
** printff
*/

#include "my.h"

void printstr(va_list *arg)
{
    char *tmp = va_arg(*arg, char *);

    my_putstr(tmp);
}

void printchar(va_list *arg)
{
    char tmp = va_arg(*arg, int);

    my_putchar(tmp);
}

void printnbr(va_list *arg)
{
    int tmp = va_arg(*arg, int);

    my_put_nbr(tmp);
}

void printnbrunsign(va_list *arg)
{
    unsigned int tmp = va_arg(*arg, int);

    my_put_nbr(tmp);
}

void printnbrhexa(va_list *arg)
{
    unsigned int tmp = va_arg(*arg, int);

    my_dec_to_hex_min(tmp);
}