/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** task05
*/

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] == '\0')
        return (0);
    for (int i = 0; to_find[i] != '\0'; i++) {
        if (str[i] != to_find[i])
            return (my_strstr(str + 1, to_find));
    }
    return (str);
}