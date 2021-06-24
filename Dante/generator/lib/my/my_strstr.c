/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** task05 day06
*/

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;

    if (str[0] == '\0')
        return (0);
    for (; str[j] != to_find[0] ; j++);
    for (; str[j] != '\0' ; j++)
        return (str);
}