/*
** EPITECH PROJECT, 2020
** printff functions
** File description:
** printff
*/

#include "my.h"

void printnbrhexamaj(va_list *arg)
{
    unsigned int tmp = va_arg(*arg, int);

    my_dec_to_hex_maj(tmp);
}