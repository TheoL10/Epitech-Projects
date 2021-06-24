/*
** EPITECH PROJECT, 2020
** prior
** File description:
** priorities
*/

void primary(char *res)
{
    for (int i = 0; res[i] != '\0'; i++) {
        if (res[i] == '/')
            division(res, i);
        if (res[i] == '%')
            modulo(res, i);
        if (res[i] == '*')
            multipl(res, i);
    }
}

void secondary(char *res, char const *av)
{
    for (int i = 0; av[i] != '%' && av[i] != '/' && av[i] != '*' ||
        av[i] == '\0'; i++) {
        if (av[i] == '+')
            addition(res, i);
        if (av[i] == '-' && is_zero(av, i) != 1)
            substraction(res, i);
    }
}

void parenthese_gest(char const *av, char *res)
{
    if (av[0] == '(' && av[my_strlen(av) - 1] == ')') {
        res[0] = 48;
        res[my_strlen(av) - 1] = '\0';
    }
}