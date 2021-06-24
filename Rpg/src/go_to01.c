/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void go_in_game(rpg_t *rpg)
{
    if (rpg->pause_menu == 0) {
        display_map(rpg);
        display_view(rpg);
        display_character(rpg);
        move_view(rpg);
        display_speech(rpg);
        menu_inventory(rpg);
        dialog_clock(rpg);
    }
    if (rpg->pause_menu == 1) {
        display_pause_menu(rpg);
    }
}

void go_main_menu(rpg_t *rpg)
{
    display_main_menu(rpg);
}

void go_set_menu(rpg_t *rpg)
{
    display_set_menu(rpg);
}

void go_cut_scene(rpg_t *rpg)
{
    download_cut_scene_clock(rpg);
    display_cut_scene(rpg);
}

void go_end_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->end_menu_spr, NULL);
}