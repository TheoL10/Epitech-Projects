/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** task08 day06
*/

char *my_strupcase(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (97 <= str[i] && str[i] <= 122)
            str[i] = str[i] - 32;
    }
    return (str);
}