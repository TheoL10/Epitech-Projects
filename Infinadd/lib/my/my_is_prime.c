/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** Task06
*/

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int prime = 2; prime < nb; prime++) {
        if (nb % prime == 0)
            return (0);
    }
    return (1);
}