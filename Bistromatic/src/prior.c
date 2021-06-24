/*
** EPITECH PROJECT, 2020
** prior
** File description:
** priorities
*/

#include "../include/my.h"

void primary(char *res)
{
    for (int i = 0; res[i] != '\0'; i++) {
        if (res[i] == '*')
            multipl(res, i, 0, 1);
    }
}

void secondary(char *av)
{
    for (int i = 0; av[i] != '%' && av[i] != '/' && av[i] != '*' &&
        av[i] != '\0'; i++) {
        if (av[i] == '+')
            addition(av, i, 0);
        if (av[i] == '-')
            substraction(av, i, 0, 0);
    }
}

void is_neg(char *av, char *before, char *after, int op)
{
    int is_neg = 0;

    for (int i = 0; after[i] != '\0';) {
        if ((after[i] > before[i] && my_strlen(after) == my_strlen(before))
            || (my_strlen(after) > my_strlen(before))) {
            is_neg = 1;
            break;
        }
        if (after[i] == before[i])
            i++;
        if (after[i] < before[i])
            break;
        if (i == 0)
            break;
    }
    if (is_neg == 1)
        av[op - my_strlen(before)] = '-';
}

int is_sup(char *before, char *after)
{
    int is_neg = 0;

    for (int i = 0; after[i] != '\0';) {
        if ((after[i] > before[i] && my_strlen(after) == my_strlen(before))
            || (my_strlen(after) > my_strlen(before))) {
            is_neg = 1;
            break;
        }
        if (after[i] == before[i])
            i++;
        if (after[i] < before[i])
            break;
        if (i == 0)
            break;
    }
    return (is_neg);
}