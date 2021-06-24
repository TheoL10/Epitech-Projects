/*
** EPITECH PROJECT, 2020
** my_put_all2
** File description:
** my_put_all2
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void my_printf_oct_nbr(va_list *ap)
{
    my_put_oct_nbr(va_arg(*ap, unsigned int));
}

void my_printf_hexa_nbr(va_list *ap)
{
    my_put_hexa_nbr(va_arg(*ap, unsigned int));
}

void my_printf_hexamaj_nbr(va_list *ap)
{
    my_put_hexamaj_nbr(va_arg(*ap, unsigned int));
}

void my_printf_bin_nbr(va_list *ap)
{
    my_put_bin_nbr(va_arg(*ap, unsigned int));
}

void my_printf_hexa2_nbr(va_list *ap)
{
    my_put_hexa2_nbr(va_arg(*ap, unsigned int));
}