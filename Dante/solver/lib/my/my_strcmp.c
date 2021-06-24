/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** task06 day06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int count1 = 0;
    int count2 = 0;

    for (; s1[i] != '\0' ; i++)
        count1 = count1 + s1[i];
    for (; s2[j] != '\0' ; j++)
        count2 = count2 + s2[j];
    if (count1 < count2)
        return (-1);
    if (count1 == count2)
        return (0);
    if (count1 > count2)
        return (1);
}