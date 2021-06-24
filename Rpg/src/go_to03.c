/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void go_to_everything(rpg_t *rpg)
{
    if (rpg->main_menu == 0)
        go_in_game(rpg);
    if (rpg->main_menu == 1)
        go_main_menu(rpg);
    if (rpg->main_menu == 2)
        go_set_menu(rpg);
    if (rpg->main_menu == 3)
        go_htp_menu(rpg);
    if (rpg->main_menu == 4)
        go_menu_combat_alde(rpg);
    if (rpg->main_menu == 5)
        go_menu_combat_jason(rpg);
    if (rpg->main_menu == 6)
        go_menu_combat_the_rock(rpg);
    if (rpg->main_menu == 7)
        go_cut_scene(rpg);
    if (rpg->main_menu == 8)
        go_end_menu(rpg);
}

void go_menu_combat_the_rock(rpg_t *rpg)
{
    rpg->menu_c_the_rock_vect = (sfVector2f)
    {(rpg->coord_view[0] - 960), (rpg->coord_view[1] - 540)};
    if (rpg->move_hand_menu_combat == 0) {
        rpg->hand_selection_vect = (sfVector2f)
        {(rpg->coord_view[0] - 60), (rpg->coord_view[1] + 240)};
        rpg->life_rock_vect = (sfVector2f)
        {(rpg->coord_view[0] - 546), (rpg->coord_view[1] - 334)};
        rpg->life_sardocho_rock_vect = (sfVector2f)
        {(rpg->coord_view[0] + 436), (rpg->coord_view[1] + 30)};
        rpg->move_hand_menu_combat = 1;
        rpg->life_rock_rect = (sfIntRect) {0, 0, 0, 18};
        rpg->life_sard_rock_rect = (sfIntRect) {0, 0, 0, 18};
    }
    go_menu_combat_the_rock2(rpg);
}

void go_menu_combat_the_rock2(rpg_t *rpg)
{
    fighting_system_for_the_rock(rpg);
    sfSprite_setTextureRect(rpg->life_rock_spr, rpg->life_rock_rect);
    sfSprite_setTextureRect(rpg->life_sard_rock_spr, rpg->life_sard_rock_rect);
    sfSprite_setPosition(rpg->menu_c_the_rock_spr, rpg->menu_c_the_rock_vect);
    sfSprite_setPosition(rpg->life_rock_spr, rpg->life_rock_vect);
    sfSprite_setPosition(rpg->life_sard_rock_spr, rpg->life_sardocho_rock_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu_c_the_rock_spr, NULL);
    sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->hand_selection_spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->life_sard_rock_spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->life_rock_spr, NULL);
}