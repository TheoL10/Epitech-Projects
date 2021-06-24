/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void fighting_system_for_alde(rpg_t *rpg)
{
    if (rpg->attaque_alde == 1) {
        rpg->life_alde_rect.width += 30;
        rpg->life_sard_alde_rect.width += 30;
        rpg->attaque_alde = 0;
    }
    if (rpg->defense_alde == 1) {
        rpg->life_alde_rect.width += 10;
        rpg->defense_alde = 0;
    }
    if (rpg->life_sard_alde_rect.width >= 386) {
        rpg->main_menu = 0;
        rpg->move_hand_menu_combat = 0;
    }
    if (rpg->life_alde_rect.width >= 386) {
        rpg->main_menu = 0;
        rpg->move_hand_menu_combat = 0;
        rpg->step_of_game = 8;
    }
}

void fighting_system_for_jason(rpg_t *rpg)
{
    if (rpg->attaque_jason == 1) {
        rpg->life_jason_rect.width += 30;
        rpg->life_sard_jason_rec.width += 30;
        rpg->attaque_jason = 0;
    }
    if (rpg->defense_jason == 1) {
        rpg->life_jason_rect.width += 10;
        rpg->defense_jason = 0;
    }
    if (rpg->life_sard_jason_rec.width >= 386) {
        rpg->main_menu = 0;
        rpg->move_hand_menu_combat = 0;
    }
    if (rpg->life_jason_rect.width >= 386) {
        rpg->main_menu = 0;
        rpg->move_hand_menu_combat = 0;
        rpg->step_of_game = 8;
    }
}

void fighting_system_for_the_rock(rpg_t *rpg)
{
    if (rpg->attaque_the_rock == 1) {
        rpg->life_rock_rect.width += 30;
        rpg->life_sard_rock_rect.width += 30;
        rpg->attaque_the_rock = 0;
    }
    if (rpg->defense_the_rock == 1) {
        rpg->life_rock_rect.width += 10;
        rpg->defense_the_rock = 0;
    }
    if (rpg->life_sard_rock_rect.width >= 386) {
        rpg->main_menu = 0;
        rpg->move_hand_menu_combat = 0;
    }
    if (rpg->life_rock_rect.width >= 386) {
        rpg->main_menu = 0;
        rpg->move_hand_menu_combat = 0;
        rpg->step_of_game = 8;
    }
}