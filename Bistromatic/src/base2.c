/*
** EPITECH PROJECT, 2020
** base2
** File description:
** base2
*/

#include "../include/my.h"

char digit_base2(char const *av, char const *base, char res, int i)
{
    if (av[i] == base[5])
        res = '5';
    if (av[i] == base[6])
        res = '6';
    if (av[i] == base[7])
        res = '7';
    if (av[i] == base[8])
        res = '8';
    if (av[i] == base[9])
        res = '9';
    return (res);
}

char rev_digit_base2(char const *base, char res)
{
    if (res == '5')
        res = base[5];
    if (res == '6')
        res = base[6];
    if (res == '7')
        res = base[7];
    if (res == '8')
        res = base[8];
    if (res == '9')
        res = base[9];
    return (res);
}