/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void init_everything2(rpg_t *rpg)
{
    init_cut_scene(rpg);
    init_download_cut_scene(rpg);
    init_text_font(rpg);
    init_music(rpg);
    init_struct(rpg);
    init_main_menu(rpg);
    init_set_menu(rpg);
    init_map(rpg);
    init_character(rpg);
    init_clock(rpg);
    init_pause_menu(rpg);
    init_speech(rpg);
    init_inventory(rpg);
    init_htp_menu(rpg);
    init_menu_combat_alde(rpg);
    init_menu_combat_jason(rpg);
    init_menu_combat_the_rock(rpg);
    init_life_bars(rpg);
    init_item_inventory(rpg);
    init_end_menu(rpg);
}