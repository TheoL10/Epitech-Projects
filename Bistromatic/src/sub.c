/*
** EPITECH PROJECT, 2020
** sub
** File description:
** sub
*/

#include "../include/my.h"
#include <stdlib.h>

char *sub2(char *before, char *after, int nb1, int nb2)
{
    int i1 = my_strlen(before) - 1;
    int i2 = my_strlen(after) - 1;
    char *result = malloc(sizeof(char) * (i1 + 1));
    int ret = 0;

    for (int i = i1; i1 >= 0 || i2 >= 0; i--, i1--, i2--) {
        if (i1 < 0)
            nb1 = 48;
        else
            nb1 = before[i1];
        if (i2 < 0)
            nb2 = 48 + ret;
        else
            nb2 = after[i2] + ret;
        ret = 0;
        if (nb2 > nb1) {
            nb1 = nb1 + 10;
            ret = 1;
        } result[i] = (nb1 - 48) - (nb2 - 48) + 48;
    } return (result);
}

char *sub3(char *before, char *after, int nb1, int nb2)
{
    int i1 = my_strlen(before) - 1;
    int i2 = my_strlen(after) - 1;
    char *result = malloc(sizeof(char) * (i2 + 1));
    int ret = 0;

    for (int i = i1 + 1; i1 >= 0 || i2 >= 0; i--, i1--, i2--) {
        nb1 = (i1 < 0) ? 48 + ret : before[i1] + ret;
        nb2 = (i2 < 0) ? 48 : after[i2];
        ret = 0;
        if (nb1 > nb2) {
            nb2 = nb2 + 10;
            ret = 1;
        }
        result[i] = (nb2 - 48) - (nb1 - 48) + 48;
    }
    if (result[0] == 0)
        result[0] = 48;
    return (result);
}