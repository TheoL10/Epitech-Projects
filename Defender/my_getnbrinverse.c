/*
** EPITECH PROJECT, 2021
** my_getnbrinverse
** File description:
** my_getnbrinverse
*/

#include "include/my.h"
#include "include/struct.h"

char *my_getnbrinverse(int tmp, int k, int trans, int is_neg)
{
    char *int_chared = malloc(sizeof(char *));
    char *intneg_chared = malloc(sizeof(char *) * (11));
    if (tmp == 0)
        return ("0");
    else { if (tmp < 0) {
            tmp = tmp * -1;
            is_neg = 1;
        }
        for (; tmp > 0; k++) { trans = tmp % 10;
            tmp = tmp / 10;
            int_chared[k] = trans + 48;
        } int_chared = my_revstr(int_chared);
        if (is_neg != 0) {
            for (int i = 0; int_chared[i] != '\0'; i++) {
                intneg_chared[0] = '-';
                intneg_chared[i + 1] = int_chared[i];
            } return (intneg_chared);
        } else
            return (int_chared); }
}