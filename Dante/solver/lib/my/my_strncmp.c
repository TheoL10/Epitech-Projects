/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** task07 day06
*/
#include<stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count1 = 0;
    int count2 = 0;

    for (int i = 0 ; s1[i] != s1[n] ; i++)
        count1 = count1 + s1[i];
    for (int j = 0 ; s2[j] != s2[n] ; j++)
        count2 = count2 + s2[j];
    if (count1 < count2)
        return (-1);
    if (count1 == count2)
        return (0);
    if (count1 > count2)
        return (1);
}