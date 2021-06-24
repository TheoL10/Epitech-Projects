/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** task03
*/

#include "../../include/my.h"
#include "../../include/struct.h"

char *my_revstr(char *str)
{
    int i = 0;
    int z = my_strlen(str) - 1;
    char a;

    while (i < z) {
        a = str[i];
        str[i] = str[z];
        str[z] = a;
        i++;
        z--;
    }
    return (str);
}
