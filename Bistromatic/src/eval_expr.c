/*
** EPITECH PROJECT, 2020
** eval_expr
** File description:
** eval_expr
*/

#include <stdlib.h>
#include "../include/my.h"

char *get_result(char *res)
{
    char *resultat_final = malloc(sizeof(char) * ((my_strlen(res) + 1)));
    int count = 0;
    int i = 0;
    int neg = 0;

    for (; res[i] == 48 || res[i] == '-'; i++) {
        if (res[i] == '-')
            neg++;
    }
    if (neg > 0) {
        resultat_final[count] = '-';
        count++;
    }
    for (; res[i] != '\0'; i++) {
        resultat_final[count] = res[i];
        count++;
    }
    if (count == 0)
        resultat_final[0] = 48;
    return (resultat_final);
}

int replace0(char *res, int count, int op)
{
    int i = count + op;

    for (; res[i] >= 48 && res[i] <= 57; i--)
        res[i] = 48;
    res[i] = 48;
    for (; res[i] >= 48 && res[i] <= 57; i--)
        res[i] = 48;
    res[count + op] = 48;
    count = count + op;
    return (count);
}

int is_zero(char const *av, int i)
{
    for (; i != -1 && av[i] == 0; i--);
    i--;
    if (av[i] >= 48 && av[i] <= 57)
        return (0);
    else
        return (1);
}

int replace(char *result, char *res, int count)
{
    int parc = (my_strlen(result) - 1);

    for (int i = count; parc >= 0; i--, parc--) {
        res[i] = result[parc];
    }
    return (0);
}

char *eval_expr(char *av)
{
    char *res = av;

    primary(res);
    secondary(res);
    return (get_result(res));
}