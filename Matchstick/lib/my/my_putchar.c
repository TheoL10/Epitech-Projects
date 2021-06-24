/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** my_putchar
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}