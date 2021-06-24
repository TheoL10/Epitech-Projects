/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** task08
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 32);
        else
            return (0);
    }
    return (str);
}