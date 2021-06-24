/*
** EPITECH PROJECT, 2021
** event04
** File description:
** event04
*/

#include "../lib/my/my.h"

void move_hand_selection_in_menu_combat_the_rock2(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased && rpg->main_menu == 6) {
        if (rpg->event.key.code == sfKeyLeft) {
            move_hand_selection_in_menu_combat_the_rock3(rpg);
        }
        if (rpg->event.key.code == sfKeyReturn) {
            move_hand_selection_in_menu_combat_the_rock4(rpg);
        }
    }
}

void move_hand_selection_in_menu_combat_the_rock3(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == (rpg->menu_c_the_rock_vect.x + 1330)) {
        rpg->hand_selection_vect.x -= 430;
        rpg->move_hand_menu_combat = 1;
    }
}

void move_hand_selection_in_menu_combat_the_rock4(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == (rpg->menu_c_the_rock_vect.x + 1330)) {
        rpg->defense_the_rock++;
        rpg->move_hand_menu_combat = 1;
    }
}