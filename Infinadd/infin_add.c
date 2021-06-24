/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** infin_add
*/

#include <stdlib.h>
#include "include/my.h"

void infin_add(char *nb1, char *nb2, int p1, int p2)
{
    int i1 = my_strlen(nb1) - 1;
    int i2 = my_strlen(nb2) - 1;
    int carry = 0;
    char *result = malloc(sizeof(char) * (i1 + i2 + 2));

    if (i1 == i2) {
        for (int a = 0; i1 >= 0 && i2 >= 0; i1--, i2--, a++) {
            result[a] = ((nb1[i1] - 48) + (nb2[i2] - 48));
            // if (carry == 1) {
            //     result[a] = result[a] + carry;
            //     carry = 0;
            // }
            // if (result[a] > 9) {
            //     result[a] = result[a] % 10;
            //     carry = 1;
            // }
            // if (i1 == 0 && carry == 1)
            //     result[a + 1] = carry + 48;
            result[a] = result[a] + 48;
        }
    }
    for (int b = 0; i1 >= 0 || i2 >= 0; i1--, i2--, b++) {
        if (i1 >= 0 || i2 >= 0)
            p1 = nb1[i1] - 48;
            p2 = nb2[i2] - 48;
        if (i1 < 0)
            p1 = 0;
        if (i2 < 0)
            p2 = 0;
        result[b] = ((p1 + p2) + 48);
    }
    my_revstr(result);
    my_putstr(result);
    my_putchar('\n');
    free(result);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return (84);
    infin_add(argv[1], argv[2], argv[3], argv[4]);
    return (0);
}