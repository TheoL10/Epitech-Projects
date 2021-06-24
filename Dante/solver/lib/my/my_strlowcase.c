/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** task09 day06
*/

char *my_strlowcase(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (65 <= str[i] && str[i] <= 90)
            str[i] = str[i] + 32;
    }

    return (str);
}
