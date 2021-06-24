/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void display_map(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->map_spr, NULL);
}

void display_view(rpg_t *rpg)
{
    if (rpg->back_from_pause_menu == 1) {
        rpg->view = sfView_createFromRect((sfFloatRect)
        {(rpg->save_coord_view[0] - 960),
        (rpg->save_coord_view[1] - 540), 1920, 1080});
        rpg->back_from_pause_menu = 0;
    }
    sfRenderWindow_setView(rpg->window, rpg->view);
}