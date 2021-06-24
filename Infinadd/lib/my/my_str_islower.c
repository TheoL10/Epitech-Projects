/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** task14
*/

int my_str_islower(char const *str)
{
    int res = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            res++;
    }
        if (res == i)
            return (1);
        if (res < i)
            return (0);
    return (0);
}