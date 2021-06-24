/*
** EPITECH PROJECT, 2020
** eval_expr
** File description:
** eval_expr
*/

#include "include/my.h"

int get_result(char *res)
{
    int result_final = 0;
    int isneg = 0;
    for (int i = 0; res[i] != '\0'; i++)
    {
        if (res[i] == '-') {
            i++;
            isneg++;
        }
        result_final = result_final * 10 + (res[i] - 48);
    }
    if (isneg > 0)
        result_final = result_final * -1;
    return (result_final);
}

int replace0(char *res, int count, int op)
{
    for (int i = count + op - 1; res[i] >= 48 && res[i] <= 57; i--) {
        res[i] = 48;
    }
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

int replace(int result, char *res, int count)
{
    if (result < 0) {
        int i = count;
        result = result * -1;

        for (; result != 0 && res[i] != '-'; i--) {
            res[i] = (result % 10) + 48;
            result = result / 10;
        }
        res[i] = '-';
    }
    else {
        for (int i = count; result != 0; i--) {
            res[i] = (result % 10) + 48;
            result = result / 10;
        }
    }
    return (0);
}

int eval_expr(char const *av)
{
    int result_final = 0;
    char *res = av;

    parenthese_gest(av, res);
    primary(res);
    secondary(res, av);
    result_final = get_result(res);
    return (result_final);
}