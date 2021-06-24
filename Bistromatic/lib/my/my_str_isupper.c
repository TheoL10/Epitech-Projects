/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** task15
*/

int my_str_isupper(char const *str)
{
    int res = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            res++;
    }
        if (res == i)
            return (1);
        if (res < i)
            return (0);
    return (0);
}