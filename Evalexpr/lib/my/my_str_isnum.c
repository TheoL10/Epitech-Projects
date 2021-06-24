/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** task13
*/

int my_str_isnum(char const *str)
{
    int res = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= '1' && str[i] <= '9')
            res++;
    }
        if (res == i)
            return (1);
        if (res < i)
            return (0);
    return (0);
}