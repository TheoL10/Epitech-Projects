/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** task12
*/

int my_str_isalpha(char const *str)
{
    int res = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            res++;
    }
        if (res == i)
            return (1);
        if (res < i)
            return (0);
    return (0);
}