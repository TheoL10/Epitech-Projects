/*
** EPITECH PROJECT, 2020
** operation
** File description:
** operation
*/

#include <stdlib.h>
#include "../include/my.h"

char *skip_zero(char *result)
{
    if (result[0] == 48) {
        int i2 = 0;
        for (int i1 = 0; result[i1] != 0; i1++) {
            i2++;
            result[i1] = result[i2];
        }
        result[i2 - 1] = '\0';
    }
    return (result);
}

char *add_inf(char *before, char *after, int nb1, int nb2)
{
    int i1 = my_strlen(before) - 1;
    int i2 = my_strlen(after) - 1;
    int carry = 0;
    int ret = 0;
    char *result = malloc(sizeof(char) * (i1 + i2 + 2));

    for (int b = 0; i1 + 1 >= 0 || i2 + 1 >= 0; i1--, i2--, b++) {
        nb1 = add_nb1(i1, nb1, before);
        nb2 = add_nb2(i2, nb2, after);
        if (carry > 0) {
            ret++;
            carry = 0;
        } ret = (nb1 + nb2 + ret);
        if (ret > 9) {
            carry++;
            ret = ret % 10;
        } result[b] = ret + 48;
        ret = 0;
    }
    return (result);
}

char *sub_inf(char *before, char *after)
{
    int i1 = my_strlen(before) - 1;
    int i2 = my_strlen(after) - 1;
    char *result = malloc(sizeof(char) * (i1 + i2 + 2));

    if (is_sup(before, after) == 0)
        result = sub2(before, after, 0, 0);
    if (is_sup(before, after) == 1)
        result = sub3(before, after, 0, 0);
    return (result);
}

int multipl(char *res, int op, int after, int len_after)
{
    char *before = get_before(res, op);
    char *result = before;

    for (int i = op + 1; res[i] >= 48 && res[i] <= 57; i++) {
        if (i - op >= 10)
            return (84);
        after = (after * 10) + res[i] - 48;
    }
    for (int i = 1; after / i >= 10; i = i *10, len_after++);
    if (after == 0) {
        replace0(res, len_after, op);
        return (0);
    }
    for (; after != 1; after--) {
        result = add_inf(before, result, 0, 0);
        my_revstr(result);
        result = get_result(result);
    } replace0(res, len_after, op);
    replace(result, res, op + len_after);
    return (0);
}