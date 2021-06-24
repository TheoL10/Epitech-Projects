/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void wich_button_when_enter_pressed(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        if (rpg->event.key.code == sfKeyReturn) {
            wich_button(rpg);
            wich_button_pause(rpg);
            select_60_fps(rpg);
            select_120_fps(rpg);
            select_volume_down(rpg);
            select_volume_up(rpg);
            select_save_settings(rpg);
            select_resize_screen(rpg);
            select_htp(rpg);
            select_htp_back(rpg);
        }
    }
}

void move_selection_from_inv(rpg_t *rpg)
{
    if (rpg->inventaire == 1) {
        if (rpg->event.type == sfEvtKeyReleased) {
            if (rpg->event.key.code == sfKeyRight)
                move_select_to_right(rpg);
        } if (rpg->event.type == sfEvtKeyReleased) {
            if (rpg->event.key.code == sfKeyLeft)
                move_select_to_left(rpg);
        } if (rpg->event.type == sfEvtKeyReleased) {
            if (rpg->event.key.code == sfKeyDown)
                move_select_to_down(rpg);
        } if (rpg->event.type == sfEvtKeyReleased) {
            if (rpg->event.key.code == sfKeyUp)
                move_select_to_up(rpg);
        }
    }
}

void move_the_character_in_game(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyRight &&
    rpg->inventaire != 1 && rpg->main_menu == 0 &&
    rpg->speech == 0) {
        rpg->walk_right = 1;
    }
    if (rpg->event.key.code == sfKeyLeft &&
    rpg->inventaire != 1 && rpg->main_menu == 0 &&
    rpg->speech == 0) {
        rpg->walk_left = 1;
    }
    if (rpg->event.key.code == sfKeyUp &&
    rpg->inventaire != 1 && rpg->main_menu == 0 &&
    rpg->speech == 0) {
        rpg->walk_toward = 1;
    }
    if (rpg->event.key.code == sfKeyDown &&
    rpg->inventaire != 1 && rpg->main_menu == 0 &&
    rpg->speech == 0) {
        rpg->walk_backward = 1;
    }
}

void move_hand_selection_in_pause_menu(rpg_t *rpg)
{
    if (rpg->pause_menu == 1) {
        if (rpg->event.key.code == sfKeyRight && rpg->inventaire != 1) {
            move_hand_selection_to_right_pause(rpg);
        }
        if (rpg->event.key.code == sfKeyLeft && rpg->inventaire != 1) {
            move_hand_selection_to_left_pause(rpg);
        }
        if (rpg->event.key.code == sfKeyUp && rpg->inventaire != 1) {
            move_hand_selection_to_hight_pause(rpg);
        }
        if (rpg->event.key.code == sfKeyDown && rpg->inventaire != 1) {
            move_hand_selection_to_low_pause(rpg);
        }
    }
}

void move_hand_selection_in_main_menu(rpg_t *rpg)
{
    if (rpg->main_menu == 1 || rpg->main_menu == 2) {
        if (rpg->event.type == sfEvtKeyReleased) {
            if (rpg->event.key.code == sfKeyRight)
                move_hand_selection_to_right(rpg);
        }
        if (rpg->event.type == sfEvtKeyReleased) {
            if (rpg->event.key.code == sfKeyLeft)
                move_hand_selection_to_left(rpg);
        }
        if (rpg->event.type == sfEvtKeyReleased) {
            if (rpg->event.key.code == sfKeyUp)
                move_hand_selection_to_high(rpg);
        }
        if (rpg->event.type == sfEvtKeyReleased) {
            if (rpg->event.key.code == sfKeyDown)
                move_hand_selection_to_low(rpg);
        }
    }
}