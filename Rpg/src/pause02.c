/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void move_hand_selection_to_right_pause(rpg_t *rpg)
{
    if (rpg->pause_menu == 1) {
        if (rpg->hand_selection_vect.x == (rpg->pause_menu_vect.x + 425))
            rpg->pause_menux += 500;
    }
}

void move_hand_selection_to_left_pause(rpg_t *rpg)
{
    if (rpg->pause_menu == 1) {
        if (rpg->hand_selection_vect.x == (rpg->pause_menu_vect.x + 925))
            rpg->pause_menux -= 500;
    }
}

void move_hand_selection_to_hight_pause(rpg_t *rpg)
{
    if (rpg->pause_menu == 1) {
        if (rpg->hand_selection_vect.x == (rpg->pause_menu_vect.x + 425)) {
            rpg->pause_menux += 1170;
            rpg->pause_menuy -= 420;
        }
        if (rpg->hand_selection_vect.x == (rpg->pause_menu_vect.x + 925)) {
            rpg->pause_menux += 670;
            rpg->pause_menuy -= 419;
        }
    }
}

void move_hand_selection_to_low_pause(rpg_t *rpg)
{
    if (rpg->pause_menu == 1) {
        if (rpg->hand_selection_vect.x == (rpg->pause_menu_vect.x + 1595)) {
            rpg->pause_menux -= 1170;
            rpg->pause_menuy += 420;
        }
    }
}

void wich_button_pause(rpg_t *rpg)
{
    if (rpg->pause_menu == 1) {
        select_main_menu_button(rpg);
        select_quit_pause_button(rpg);
        select_settings_pause_button(rpg);
    }
}