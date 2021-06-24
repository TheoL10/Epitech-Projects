/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void go_htp_menu(rpg_t *rpg)
{
    rpg->hand_selection_vect.x = 20;
    rpg->hand_selection_vect.y = 20;
    sfRenderWindow_drawSprite(rpg->window, rpg->htp_menu_spr, NULL);
    sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->hand_selection_spr, NULL);
}

void go_menu_combat_alde(rpg_t *rpg)
{
    rpg->menu_combat_alde_vect = (sfVector2f)
    {(rpg->coord_view[0] - 960), (rpg->coord_view[1] - 540)};
    if (rpg->move_hand_menu_combat == 0) {
        rpg->hand_selection_vect = (sfVector2f)
        {(rpg->coord_view[0] - 60), (rpg->coord_view[1] + 240)};
        rpg->life_alde_vect = (sfVector2f)
        {(rpg->coord_view[0] - 546), (rpg->coord_view[1] - 334)};
        rpg->life_sardocho_alde_vect = (sfVector2f)
        {(rpg->coord_view[0] + 436), (rpg->coord_view[1] + 30)};
        rpg->move_hand_menu_combat = 1;
        rpg->life_alde_rect = (sfIntRect) {0, 0, 0, 18};
        rpg->life_sard_alde_rect = (sfIntRect) {0, 0, 0, 18};
    }
    go_menu_combat_alde2(rpg);
}

void go_menu_combat_alde2(rpg_t *rpg)
{
    fighting_system_for_alde(rpg);
    sfSprite_setTextureRect(rpg->life_alde_spr, rpg->life_alde_rect);
    sfSprite_setTextureRect(rpg->life_sard_alde_spr, rpg->life_sard_alde_rect);
    sfSprite_setPosition(rpg->menu_combat_alde_spr, rpg->menu_combat_alde_vect);
    sfSprite_setPosition(rpg->life_alde_spr, rpg->life_alde_vect);
    sfSprite_setPosition(rpg->life_sard_alde_spr, rpg->life_sardocho_alde_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu_combat_alde_spr, NULL);
    sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->hand_selection_spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->life_sard_alde_spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->life_alde_spr, NULL);
}

void go_menu_combat_jason(rpg_t *rpg)
{
    rpg->menu_comb_jason_vect = (sfVector2f)
    {(rpg->coord_view[0] - 960), (rpg->coord_view[1] - 540)};
    if (rpg->move_hand_menu_combat == 0) {
        rpg->hand_selection_vect = (sfVector2f)
        {(rpg->coord_view[0] - 60), (rpg->coord_view[1] + 240)};
        rpg->life_jason_vect = (sfVector2f)
        {(rpg->coord_view[0] - 546), (rpg->coord_view[1] - 334)};
        rpg->life_sard_jason_vect = (sfVector2f)
        {(rpg->coord_view[0] + 436), (rpg->coord_view[1] + 30)};
        rpg->move_hand_menu_combat = 1;
        rpg->life_jason_rect = (sfIntRect) {0, 0, 0, 18};
        rpg->life_sard_jason_rec = (sfIntRect) {0, 0, 0, 18};
    }
    go_menu_combat_jason2(rpg);
}

void go_menu_combat_jason2(rpg_t *rpg)
{
    fighting_system_for_jason(rpg);
    sfSprite_setTextureRect(rpg->life_jason_spr, rpg->life_jason_rect);
    sfSprite_setTextureRect(rpg->life_sard_jason_spr, rpg->life_sard_jason_rec);
    sfSprite_setPosition(rpg->menu_combat_jason_spr, rpg->menu_comb_jason_vect);
    sfSprite_setPosition(rpg->life_jason_spr, rpg->life_jason_vect);
    sfSprite_setPosition(rpg->life_sard_jason_spr, rpg->life_sard_jason_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->menu_combat_jason_spr, NULL);
    sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->hand_selection_spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->life_sard_jason_spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->life_jason_spr, NULL);
}