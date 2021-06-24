/*
** EPITECH PROJECT, 2020
** base
** File description:
** base
*/

#include "../include/my.h"

char *op_base(char const *av, char const *base, char *res, int size)
{
    int i = 0;

    for (i = 0; i <= size; i++) {
        if (av[i] == base[0])
            res[i] = '(';
        if (av[i] == base[1])
            res[i] = ')';
        if (av[i] == base[2])
            res[i] = '+';
        if (av[i] == base[3])
            res[i] = '-';
        if (av[i] == base[4])
            res[i] = '*';
        if (av[i] == base[5])
            res[i] = '/';
        if (av[i] == base[6])
            res[i] = '%';
    }
    res[i] = '\0';
    return (res);
}

char *rev_op_base(char *res, char const *base, int size)
{
    int i = 0;

    for (i = 0; i <= size; i++) {
        if (res[i] == '(')
            res[i] = base[0];
        if (res[i] == ')')
            res[i] = base[1];
        if (res[i] == '+')
            res[i] = base[2];
        if (res[i] == '-')
            res[i] = base[3];
        if (res[i] == '*')
            res[i] = base[4];
        if (res[i] == '/')
            res[i] = base[5];
        if (res[i] == '%')
            res[i] = base[6];
    }
    res[i] = '\0';
    return (res);
}

char *digit_base(char const *av, char const *base, char *res, int size)
{
    int i = 0;

    for (i = 0; i <= size; i++) {
        if (av[i] == base[0])
            res[i] = '0';
        if (av[i] == base[1])
            res[i] = '1';
        if (av[i] == base[2])
            res[i] = '2';
        if (av[i] == base[3])
            res[i] = '3';
        if (av[i] == base[4])
            res[i] = '4';
        res[i] = digit_base2(av, base, res[i], i);
    }
    res[i] = '\0';
    return (res);
}

char *rev_digit_base(char *res, char const *base, int size)
{
    int i = 0;

    for (i = 0; i <= size; i++) {
        if (res[i] == '0')
            res[i] = base[0];
        if (res[i] == '1')
            res[i] = base[1];
        if (res[i] == '2')
            res[i] = base[2];
        if (res[i] == '3')
            res[i] = base[3];
        if (res[i] == '4')
            res[i] = base[4];
        res[i] = rev_digit_base2(base, res[i]);
    }
    res[i] = '\0';
    return (res);
}