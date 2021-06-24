/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** lib
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int n = 0;

    for (; dest[i] != '\0' ; i++);
    for (; src[n] != '\0' ; n++) {
        dest[i] = src [n];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
