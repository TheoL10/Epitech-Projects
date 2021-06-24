/*
** EPITECH PROJECT, 2020
** operande
** File description:
** operande
*/

#include "include/my.h"

void addition(char *res, int op, int result)
{
    int before = 0;
    int after = 0;
    int count = 0;

    for (int mult = 1; res[op - 1] >= 48 && res[op - 1] <= 57; op--, count++) {
        before = before + (res[op - 1] - 48) * mult;
        mult = mult * 10;
    }
    count = replace0(res, count, op);
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++)
        after = (after * 10) + res[i] - 48;
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++) {
        res[i] = 48;
        count = i;
    }
    if (res[op - 1] == '-')
        result = after - before;
    else
        result = before + after;
    replace(result, res, count);
}

void substraction(char *res, int op, int result)
{
    int before = 0;
    int after = 0;
    int count = 0;

    for (int mult = 1; res[op - 1] >= 48 && res[op - 1] <= 57; op--, count++) {
        before = before + (res[op - 1] - 48) * mult;
        mult = mult * 10;
    }
    count = replace0(res, count, op);
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++)
        after = (after * 10) + res[i] - 48;
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++) {
        res[i] = 48;
        count = i;
    }
    if (res[op - 1] == '-')
        result = (after - before);
    else
        result = before - after;
    replace(result, res, count);
}

int division(char *res, int op, int result)
{
    int before = 0;
    int after = 0;
    int count = 0;

    for (int mult = 1; res[op - 1] >= 48 && res[op - 1] <= 57; op--) {
        before = before + (res[op - 1] - 48) * mult;
        mult = mult * 10;
        count++;
    }
    count = replace0(res, count, op);
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++)
        after = (after * 10) + res[i] - 48;
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++) {
        res[i] = 48;
        count = i;
    }
    result = before / after;
    replace(result, res, count);
    return (result);
}

int modulo(char *res, int op)
{
    int before = 0;
    int after = 0;
    int count = 0;
    int result = 0;

    for (int mult = 1; res[op - 1] >= 48 && res[op - 1] <= 57; op--) {
        before = before + (res[op - 1] - 48) * mult;
        mult = mult * 10;
        count++;
    }
    count = replace0(res, count, op);
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++)
        after = (after * 10) + res[i] - 48;
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++) {
        res[i] = 48;
        count = i;
    }
    result = before % after;
    replace(result, res, count);
    return (result);
}

int multipl(char *res, int op)
{
    int before = 0;
    int after = 0;
    int count = 0;
    int result = 0;

    for (int mult = 1; res[op - 1] >= 48 && res[op - 1] <= 57; op--) {
        before = before + (res[op - 1] - 48) * mult;
        mult = mult * 10;
        count++;
    }
    count = replace0(res, count, op );
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++)
        after = (after * 10) + res[i] - 48;
    for (int i = count; res[i] >= 48 && res[i] <= 57; i++) {
        res[i] = 48;
        count = i;
    }
    result = before * after;
    replace(result, res, count);
    return (result);
}