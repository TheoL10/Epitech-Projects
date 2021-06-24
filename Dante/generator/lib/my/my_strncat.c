/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** lib
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int u = 0;

    for (; dest[i] != '\0' ; i++);
    for (; u < nb ; u++) {
        dest[i] = src [u];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}