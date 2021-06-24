/*
** EPITECH PROJECT, 2020
** operande
** File description:
** operande
*/

#include <stdlib.h>
#include "../include/my.h"

void addition(char *av, int op, int end)
{
    char *res = av;
    char *before = malloc(sizeof(char) * (my_strlen(res) + 1));
    char *after = malloc(sizeof(char) * (my_strlen(res) + 1));
    int count = 0;

    for (int i = op - 1; res[i] >= 48 && res[i] <= 57; i--) {
        before[count] = res[i];
        count++;
    }
    count = 0;
    for (int i = op + 1; res[i] >= 48 && res[i] <= 57; i++) {
        end = i;
        after[count] = res[i];
        count++;
    }
    my_revstr(before);
    res = add_inf(before, after, 0, 0);
    my_revstr(res);
    replace0(av, my_strlen(after), op);
    replace(res, av, end);
}

void substraction(char *av, int op, int end, int cnt)
{
    char *res = av;
    char *before = malloc(sizeof(char) * (my_strlen(res) + 1));
    char *after = malloc(sizeof(char) * (my_strlen(res) + 1));
    int k = op - 1;

    for (; res[k] >= 48 && res[k] <= 57; k--);
    for (; k != op; k++) {
        if ((res[k] <= 57 && res[k] > 48) ||
            (res[k] <= 57 && res[k] >= 48 && cnt != 0)) {
            before[cnt] = av[k];
            cnt++;
        }
    }
    cnt = (cnt == 0) ? 48 : 0;
    for (int i = op + 1; res[i] >= 48 && res[i] <= 57; i++, cnt++, end = i - 1)
        after[cnt] = res[i];
    res = sub_inf(before, after);
    replace0(av, my_strlen(after), op);
    replace(res, av, end);
    is_neg(av, before, after, op);
}

char *get_before(char *av, int op)
{
    char *res = av;
    char *before = malloc(sizeof(char) * (my_strlen(res) + 1));
    int count = 0;

    for (int i = op - 1; res[i] >= 48 && res[i] <= 57; i--) {
        before[count] = res[i];
        count++;
    }
    my_revstr(before);
    return (before);
}