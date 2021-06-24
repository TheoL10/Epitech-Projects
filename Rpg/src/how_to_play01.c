/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void select_htp(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 1632 && rpg->hand_selection_vect.y == 927)
        rpg->main_menu = 3;
}

void select_htp_back(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 20 && rpg->hand_selection_vect.y == 20) {
        rpg->hand_selection_vect.x = 362;
        rpg->hand_selection_vect.y = 512;
        rpg->main_menu = 1;
    }
}