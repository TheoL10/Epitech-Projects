/*
** EPITECH PROJECT, 2020
** my_put_all
** File description:
** my_put_all
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void my_printf_str(va_list *ap)
{
    my_putstr(va_arg(*ap, char *));
}

void my_printf_char(va_list *ap)
{
    my_putchar(va_arg(*ap, int));
}

void my_printf_nbr(va_list *ap)
{
    my_put_nbr(va_arg(*ap, int));
}

void my_printf_unsigned_nbr(va_list *ap)
{
    my_put_unsigned_nbr(va_arg(*ap, int));
}

void my_printf_pourcent(void)
{
    my_putchar('%');
}