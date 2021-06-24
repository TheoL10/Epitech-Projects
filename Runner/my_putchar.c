/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(int c)
{
    write(1, &c, 1);
}