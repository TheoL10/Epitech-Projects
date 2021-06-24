/*
** EPITECH PROJECT, 2021
** menu03
** File description:
** menu03
*/

#include "../lib/my/my.h"

void move_hand_selection_to_low3(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.y == 512
        && rpg->hand_selection_vect.x == 862) {
            rpg->hand_selection_vect.y += 415;
            rpg->hand_selection_vect.x += 770;
    }
}

void move_hand_selection_to_low2(rpg_t *rpg)
{
    if (rpg->main_menu == 2) {
        if (rpg->hand_selection_vect.x == 850
        && rpg->hand_selection_vect.y == 409) {
            rpg->hand_selection_vect.y += 290;
        }
        if (rpg->hand_selection_vect.x == 850
        && rpg->hand_selection_vect.y == 119) {
            rpg->hand_selection_vect.y += 290;
        }
        if (rpg->hand_selection_vect.x == 325
        && rpg->hand_selection_vect.y == 409) {
            rpg->hand_selection_vect.y += 290;
        }
        if (rpg->hand_selection_vect.x == 325
        && rpg->hand_selection_vect.y == 119) {
            rpg->hand_selection_vect.y += 290;
        }
        move_hand_selection_to_low4(rpg);
    }
}

void move_hand_selection_to_low4(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 20) {
            rpg->hand_selection_vect.x += 305;
            rpg->hand_selection_vect.y += 110;
        }
}

void wich_button(rpg_t *rpg)
{
    if (rpg->main_menu == 1) {
        select_playing_button(rpg);
        select_quit_button(rpg);
        select_set_button(rpg);
    }
    if (rpg->main_menu == 2) {
        select_quit_menu_button(rpg);
    }
}

void select_playing_button(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 362) {
        if (rpg->if_already_cutscene == 0)
            rpg->main_menu = 7;
        if (rpg->if_already_cutscene == 1)
            rpg->main_menu = 0;
    }
}