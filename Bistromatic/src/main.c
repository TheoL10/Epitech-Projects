/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/my.h"

int check_bracket(char *expr)
{
    int i = 0;
    int start = 0;
    int end = 0;

    for (i = 0; (expr[i] > '9' || expr[i] < '0') && expr[i]; i++);
    if ((expr[i - 1] == ')' || expr[i + 1] == '('))
        return (0);
    for (int j = 0; expr[j] != '\0'; j++){
        if (expr[j] == '(')
            start++;
        if (expr[j] == ')')
            end++;
    }
    if (end != start)
        return (0);
    return (1);
}

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 2);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    for (int i = 0; ops[i] != '\0'; i++) {
        for (int k = 0; ops[k] != '\0'; k++) {
            if (ops[i] == ops[k] && k != i) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_OPS);
            }
        }
    }
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    for (int i = 0; b[i] != '\0'; i++) {
        for (int k = 0; b[k] != '\0'; k++) {
            if (b[i] == b[k] && k != i) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_BASE);
            }
        }
    }
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (av[1][0] == '-' && av[1][1] == 'h') {
        error();
        return (0);
    }
    error3(ac, av);
    check_base(av[1]);
    check_ops(av[2]);
    check_ops_base(av[1], av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    if (check_bracket(expr) == 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        return (EXIT_EXPR);
    }
    my_putstr(eval_expr(expr));
    free(expr);
    return (EXIT_SUCCESS);
}