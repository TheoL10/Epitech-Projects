/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void select_60_fps(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 325
    && rpg->hand_selection_vect.y == 409) {
        sfRenderWindow_setFramerateLimit(rpg->window, 60);
    }
}

void select_set_button(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 1630) {
        rpg->main_menu = 2;
        rpg->hand_selection_vect.x -= 1305;
        rpg->hand_selection_vect.y += 410;
    }
}

void select_quit_menu_button(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 20 && rpg->hand_selection_vect.y == 9) {
        if (rpg->if_in_pause_menu == 0) {
            rpg->main_menu = 1;
            rpg->hand_selection_vect.x = 362;
            rpg->hand_selection_vect.y = 512;
        }
        if (rpg->if_in_pause_menu == 1) {
            rpg->main_menu = 0;
            rpg->pause_menu = 1;
            rpg->if_in_pause_menu = 0;
        }
    }
}