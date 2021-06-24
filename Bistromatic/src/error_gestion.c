/*
** EPITECH PROJECT, 2020
** error_gestion
** File description:
** error_gestion
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/my.h"

void error(void)
{
    write(1, "USAGE\n", 6);
    write(1, "./calc base operators size_read\n\n", 33);
    write(1, "DESCRIPTION\n", 12);
    write(1, "- base: all the symbols of the base\n", 36);
    write(1, "- operators: ", 13);
    write(1, "the symbols for the parentheses and the 5 operators\n", 52);
    write(1, "- size_read: number of characters to be read\n", 45);
}

void error2(char **av)
{
    my_putstr("Usage: ");
    my_putstr(av[0]);
    my_putstr(" base ops\"()+_*/%\" exp_len\n");
}

int error3(int ac, char **av)
{
    if (ac != 4) {
        error2(av);
        return (EXIT_USAGE);
    }
    return (0);
}

int check_ops_base(char const *ops, char const *b)
{
    for (int i = 0; ops[i] != '\0'; i++) {
        for (int k = 0; b[k] != '\0'; k++) {
            if (ops[i] == b[k] && i != k) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_OPS);
            }
        }
    }
    return (0);
}