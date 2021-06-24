/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int p = 0;

    if (nb < 0)
        return (0);
    while ((p * p) != nb) {
        if ((p * p) > nb)
            return (0);
        p++;
    }
    return (p);
}
