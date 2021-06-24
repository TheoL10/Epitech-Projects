/*
** EPITECH PROJECT, 2020
** addinf
** File description:
** addinf
*/

int add_nb1(int i1, int nb1, char *before)
{
    nb1 = before[i1] - 48;
    if (i1 < 0)
        return (0);
    return (nb1);
}

int add_nb2(int i2, int nb2, char *after)
{
    nb2 = after[i2] - 48;
    if (i2 < 0)
        return (0);
    return (nb2);
}