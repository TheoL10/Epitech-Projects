/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib
*/

#include "my.h"

char **my_str_to_chartab(char *buffer)
{
    int len_buff = (my_strlen(buffer) + 1);
    char **strtab = malloc(sizeof(char *) * (len_buff));
    int pos_tabgen = 0;
    int m = 0;

    for (int a = 0; a != len_buff; a++)
        strtab[a] = malloc(sizeof(char) * (len_buff));
    for (int w = 0; buffer[w] != '\0'; w++) {
        if (buffer[w] != ',') {
            strtab[pos_tabgen][m] = buffer[w];
            m++;
        }
        if (buffer[w] == '\n') {
            pos_tabgen++;
            m = 0;
        }
    }
    return (strtab);
}

char **my_str_to_chartab_dialog(char *buffer)
{
    int len_buff = (my_strlen(buffer + 1));
    char **strtab = malloc(sizeof(char *) * (len_buff));
    int pos_tabgen = 0;
    int m = 0;
    int w = 0;

    for (int a = 0; a != len_buff; a++)
        strtab[a] = malloc(sizeof(char) * (len_buff));
    for (; buffer[w] != '\0'; w++) {
        if (buffer[w] != '\n') {
            strtab[pos_tabgen][m] = buffer[w];
            m++;
        }
        if (buffer[w] == '\n') {
            strtab[pos_tabgen][m] = '\0';
            pos_tabgen++;
            m = 0;
        }
    }
    return (strtab);
}