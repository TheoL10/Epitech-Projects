/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void open_the_inventaire(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue)
        rpg->inventaire = 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue) {
            rpg->inventaire = 0;
            rpg->set_pos = 0;
    }
}

void close_the_pause_menu(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        if (rpg->event.key.code == sfKeyEscape) {
            rpg->pause_menu2 = 0;
            if (rpg->pause_menu == 1) {
                rpg->pause_menu = 0;
                rpg->pause_menu2 = 1;
            }
            if (rpg->pause_menu == 0 && rpg->pause_menu2 != 1) {
                rpg->pause_menu = 1;
            }
        }
    }
}

void move_hand_selection_in_menu_combat_alde(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased && rpg->main_menu == 4) {
        if (rpg->event.key.code == sfKeyRight) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_combat_alde_vect.x + 900)) {
                rpg->hand_selection_vect.x += 430;
                rpg->move_hand_menu_combat = 1;
            }
        }
        if (rpg->event.key.code == sfKeyReturn) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_combat_alde_vect.x + 900)) {
                rpg->attaque_alde++;
                rpg->move_hand_menu_combat = 1;
            }
        }
    }
    move_hand_selection_in_menu_combat_alde2(rpg);
}

void move_hand_selection_in_menu_combat_alde2(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased && rpg->main_menu == 4) {
        if (rpg->event.key.code == sfKeyLeft) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_combat_alde_vect.x + 1330)) {
                rpg->hand_selection_vect.x -= 430;
                rpg->move_hand_menu_combat = 1;
            }
        }
        if (rpg->event.key.code == sfKeyReturn) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_combat_alde_vect.x + 1330)) {
                rpg->defense_alde++;
                rpg->move_hand_menu_combat = 1;
            }
        }
    }
}

void move_hand_selection_in_menu_combat_jason(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased && rpg->main_menu == 5) {
        if (rpg->event.key.code == sfKeyRight) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_comb_jason_vect.x + 900)) {
                rpg->hand_selection_vect.x += 430;
                rpg->move_hand_menu_combat = 1;
            }
        }
        if (rpg->event.key.code == sfKeyReturn) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_comb_jason_vect.x + 900)) {
                rpg->attaque_jason++;
                rpg->move_hand_menu_combat = 1;
            }
        }
    }
    move_hand_selection_in_menu_combat_jason2(rpg);
}