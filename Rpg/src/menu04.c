/*
** EPITECH PROJECT, 2021
** menu04
** File description:
** menu04
*/

#include "../lib/my/my.h"

void select_quit_button(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 862)
        sfRenderWindow_close(rpg->window);
}