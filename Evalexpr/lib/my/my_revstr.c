/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int z = my_strlen(str) - 1;
    char a;

    while (i < z) {
        a = str[i];
        str[i] = str[z];
        str[z] = a;
        i++;
        z--;
    }
    return (str);
}
