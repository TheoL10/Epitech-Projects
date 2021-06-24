/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** task03 day06
*/
#include<unistd.h>

char *my_revstr(char *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;
    char *a = str;
    char *b = (str + i - 1);
    char c;

    while (a <= b)
    {
        c = *a;
        *a = *b;
        *b = c;
        a++;
        b--;
    }
    return (str);
}