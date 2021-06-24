/*
** EPITECH PROJECT, 2021
** lib
** File description:
** lib
*/

#include "my.h"

char **my_str_to_wordtab(char *buffer, char c)
{
    int nbr_of_word = 0;
    int len_buff = (my_strlen(buffer) + 1);
    char **strtab = malloc(sizeof(char *) * (len_buff + 100));
    int pos_tablittl = 0;
    int pos_tabgen = 0;

    for (int a = 0; a != len_buff; a++)
        strtab[a] = malloc(sizeof(char) * (len_buff));
    for (int w = 0; buffer[w] != '\0'; w++) {
        if (buffer[w] != c) {
            strtab[pos_tabgen][pos_tablittl] = buffer[w];
            pos_tablittl++;
        }
        if (buffer[w] == c) {
            pos_tabgen++;
            pos_tablittl = 0;
        }
    }
    strtab[pos_tabgen + 1] = NULL;
    return (strtab);
}