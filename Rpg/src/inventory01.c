/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void menu_inventory(rpg_t *rpg)
{
    if (rpg->inventaire == 1) {
        menu_inventory_init(rpg);
        menu_inventory_draw_set(rpg);
        menu_inventory_place_items(rpg);
    }
}

void menu_inventory_init(rpg_t *rpg)
{
    rpg->inventory_vect = (sfVector2f)
    {(rpg->coord_view[0] - 512), (rpg->coord_view[1] - 270)};
    rpg->item_bob_lorenzo_vect = (sfVector2f)
    {(rpg->coord_view[0] - 458), (rpg->coord_view[1] - 205)};
    rpg->item_dollars_vect = (sfVector2f)
    {(rpg->coord_view[0] - 365), (rpg->coord_view[1] - 220)};
    rpg->item_wati_vect = (sfVector2f)
    {(rpg->coord_view[0] - 458), (rpg->coord_view[1] - 120)};
    rpg->item_bugatti_vect = (sfVector2f)
    {(rpg->coord_view[0] - 275), (rpg->coord_view[1] - 210)};
    rpg->item_ak_vect = (sfVector2f)
    {(rpg->coord_view[0] - 190), (rpg->coord_view[1] - 210)};
    rpg->item_alk_vect = (sfVector2f)
    {(rpg->coord_view[0] - 367), (rpg->coord_view[1] - 125)};
    if (rpg->set_pos == 0) {
        rpg->select_vect = (sfVector2f)
        {(rpg->coord_view[0] - 475), (rpg->coord_view[1] - 235)};
        rpg->set_pos = 1;
    }
}

void menu_inventory_place_items(rpg_t *rpg)
{
    if (rpg->step_of_game >= 1)
        sfRenderWindow_drawSprite(rpg->window, rpg->item_bob_lorenzo_spr, NULL);
    if (rpg->step_of_game >= 2)
        sfRenderWindow_drawSprite(rpg->window, rpg->item_dollars_spr, NULL);
    if (rpg->step_of_game >= 3)
        sfRenderWindow_drawSprite(rpg->window, rpg->item_bugatti_spr, NULL);
    if (rpg->step_of_game >= 4)
        sfRenderWindow_drawSprite(rpg->window, rpg->item_ak_spr, NULL);
    if (rpg->step_of_game >= 5)
        sfRenderWindow_drawSprite(rpg->window, rpg->item_wati_spr, NULL);
    if (rpg->step_of_game >= 6)
        sfRenderWindow_drawSprite(rpg->window, rpg->item_alk_spr, NULL);
}

void menu_inventory_draw_set(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->inventory_spr, rpg->inventory_vect);
    sfSprite_setPosition(rpg->select_spr, rpg->select_vect);
    sfSprite_setPosition(rpg->item_bob_lorenzo_spr, rpg->item_bob_lorenzo_vect);
    sfSprite_setPosition(rpg->item_dollars_spr, rpg->item_dollars_vect);
    sfSprite_setPosition(rpg->item_ak_spr, rpg->item_ak_vect);
    sfSprite_setPosition(rpg->item_wati_spr, rpg->item_wati_vect);
    sfSprite_setPosition(rpg->item_bugatti_spr, rpg->item_bugatti_vect);
    sfSprite_setPosition(rpg->item_alk_spr, rpg->item_alk_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->inventory_spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->select_spr, NULL);
}