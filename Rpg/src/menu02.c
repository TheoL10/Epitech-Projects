/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void move_hand_selection_to_right(rpg_t *rpg)
{
    if (rpg->main_menu == 1) {
        if (rpg->hand_selection_vect.x == 362)
            rpg->hand_selection_vect.x += 500;
    }
    if (rpg->main_menu == 2) {
        if (rpg->hand_selection_vect.x == 325
        && rpg->hand_selection_vect.y == 119) {
            rpg->hand_selection_vect.x += 525;
        }
        if (rpg->hand_selection_vect.x == 325
        && rpg->hand_selection_vect.y == 409) {
            rpg->hand_selection_vect.x += 525;
        }
        if (rpg->hand_selection_vect.x == 325
        && rpg->hand_selection_vect.y == 699) {
            rpg->hand_selection_vect.x += 525;
        }
    }
}

void move_hand_selection_to_left(rpg_t *rpg)
{
    if (rpg->main_menu == 1) {
        if (rpg->hand_selection_vect.x == 862)
            rpg->hand_selection_vect.x -= 500;
    }
    if (rpg->main_menu == 2) {
        if (rpg->hand_selection_vect.x == 850
        && rpg->hand_selection_vect.y == 119)
            rpg->hand_selection_vect.x -= 525;
        if (rpg->hand_selection_vect.x == 850
        && rpg->hand_selection_vect.y == 409)
            rpg->hand_selection_vect.x -= 525;
        if (rpg->hand_selection_vect.x == 850
        && rpg->hand_selection_vect.y == 699)
            rpg->hand_selection_vect.x -= 525;
    }
}

void move_hand_selection_to_high(rpg_t *rpg)
{
    if (rpg->main_menu == 1) {
        if (rpg->hand_selection_vect.x == 362) {
            rpg->hand_selection_vect.x += 1268;
            rpg->hand_selection_vect.y -= 513;
        }
        if (rpg->hand_selection_vect.x == 862) {
            rpg->hand_selection_vect.x += 768;
            rpg->hand_selection_vect.y -= 513;
        }
        if (rpg->hand_selection_vect.y == 927) {
            rpg->hand_selection_vect.x -= 1270;
            rpg->hand_selection_vect.y -= 415;
        }
    }
    move_hand_selection_to_high2(rpg);
}

void move_hand_selection_to_high2(rpg_t *rpg)
{
    if (rpg->main_menu == 2) {
        if (rpg->hand_selection_vect.x == 325
        && rpg->hand_selection_vect.y == 119) {
            rpg->hand_selection_vect.x -= 305;
            rpg->hand_selection_vect.y -= 110;
        }
        if (rpg->hand_selection_vect.x == 325
        && rpg->hand_selection_vect.y == 409)
            rpg->hand_selection_vect.y -= 290;
        if (rpg->hand_selection_vect.x == 325
        && rpg->hand_selection_vect.y == 699)
            rpg->hand_selection_vect.y -= 290;
        if (rpg->hand_selection_vect.x == 850
        && rpg->hand_selection_vect.y == 409)
            rpg->hand_selection_vect.y -= 290;
        if (rpg->hand_selection_vect.x == 850
        && rpg->hand_selection_vect.y == 699)
            rpg->hand_selection_vect.y -= 290;
    }
}

void move_hand_selection_to_low(rpg_t *rpg)
{
    if (rpg->main_menu == 1) {
        if (rpg->hand_selection_vect.x == 1630) {
            rpg->hand_selection_vect.x -= 1268;
            rpg->hand_selection_vect.y += 513;
        }
    }
    if (rpg->main_menu == 1) {
        if (rpg->hand_selection_vect.x == 1626) {
            rpg->hand_selection_vect.x -= 764;
            rpg->hand_selection_vect.y += 513;
        }
        if (rpg->hand_selection_vect.y == 512
        && rpg->hand_selection_vect.x == 362) {
            rpg->hand_selection_vect.y += 415;
            rpg->hand_selection_vect.x += 1270;
        }
        move_hand_selection_to_low3(rpg);
    }
    move_hand_selection_to_low2(rpg);
}