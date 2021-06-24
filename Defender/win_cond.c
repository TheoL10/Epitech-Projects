/*
** EPITECH PROJECT, 2021
** win
** File description:
** win
*/

#include "include/my.h"
#include "include/struct.h"

void win_cond(defender_t *defender)
{
    if (defender->gold >= 4000)
        defender->count_menu = 5;
    if (defender->count_menu == 5) {
        sfRenderWindow_drawSprite(defender->window, defender->win, NULL);
    }
}