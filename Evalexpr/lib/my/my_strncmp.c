/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != "\0" && s2[i] != '\0' && n > i; i++)
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] == '\0' && s2[i] == '\0' || i == n)
            return (0);
        else
            return (1);
}