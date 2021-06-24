/*
** EPITECH PROJECT, 2021
** event3
** File description:
** event3
*/

#include "../lib/my/my.h"

void close_the_window(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
}

void skip_cut_scene(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased && rpg->main_menu == 7) {
        if (rpg->event.key.code == sfKeyA) {
            rpg->main_menu = 0;
            rpg->if_already_cutscene = 1;
        }
    }
}

void quit_end_menu(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased && rpg->main_menu == 8) {
        if (rpg->event.key.code == sfKeyM) {
            sfRenderWindow_close(rpg->window);
        }
    }
}

void move_hand_selection_in_menu_combat_jason2(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased && rpg->main_menu == 5) {
        if (rpg->event.key.code == sfKeyLeft) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_comb_jason_vect.x + 1330)) {
                rpg->hand_selection_vect.x -= 430;
                rpg->move_hand_menu_combat = 1;
            }
        }
        if (rpg->event.key.code == sfKeyReturn) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_comb_jason_vect.x + 1330)) {
                rpg->defense_jason++;
                rpg->move_hand_menu_combat = 1;
            }
        }
    }
}

void move_hand_selection_in_menu_combat_the_rock(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased && rpg->main_menu == 6) {
        if (rpg->event.key.code == sfKeyRight) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_c_the_rock_vect.x + 900)) {
                rpg->hand_selection_vect.x += 430;
                rpg->move_hand_menu_combat = 1;
            }
        }
        if (rpg->event.key.code == sfKeyReturn) {
            if (rpg->hand_selection_vect.x ==
            (rpg->menu_c_the_rock_vect.x + 900)) {
                rpg->attaque_the_rock++;
                rpg->move_hand_menu_combat = 1;
            }
        }
    }
    move_hand_selection_in_menu_combat_the_rock2(rpg);
}