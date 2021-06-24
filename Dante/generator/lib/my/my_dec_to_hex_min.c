/*
** EPITECH PROJECT, 2020
** lib epitech 2020
** File description:
** lib
*/

#include "my.h"

void my_dec_to_hex_min(int decimalnbr)
{
    int quotient = decimalnbr;
    int remainder = 0;
    int j = 0;
    char hexadecimalnum[100];

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 87 + remainder;
        quotient = quotient / 16;
    }
    my_revstr(hexadecimalnum);
    my_putstr(hexadecimalnum);
}