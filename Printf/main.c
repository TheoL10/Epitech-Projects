/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"

int main(void)
{
    my_printf("Main test : \n");
    printf("printf version : %s %c %d %i %u %x %X %p %o %u %% %s\n", "hello", 'Y', 32, 45, 89, 3500, 3500, 3500, 3500, 3500, "110110101100");
    my_printf("my_printf version : %s %c %d %i %u %x %X %p %o %u %% %b\n", "hello", 'Y', 32, 45, 89, 3500, 3500, 3500, 3500, 3500, 3500);
    return (0);
}