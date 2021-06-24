/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{
    int res;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    else
        return (res = nb * my_compute_power_rec(nb, p - 1));
}
