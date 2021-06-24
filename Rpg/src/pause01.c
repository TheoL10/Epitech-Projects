/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void init_pause_menu(rpg_t *rpg)
{
    rpg->pause_menu_spr = sfSprite_create();
    rpg->pause_menu_text =
    sfTexture_createFromFile("assets/pause_menu.png", NULL);
    sfSprite_setTexture(rpg->pause_menu_spr, rpg->pause_menu_text, sfTrue);
}

void display_pause_menu(rpg_t *rpg)
{
    rpg->coord_view = rpg->view;
    rpg->pause_menu_vect = (sfVector2f)
    {(rpg->coord_view[0] - 960), (rpg->coord_view[1] - 540)};
    sfSprite_setPosition(rpg->pause_menu_spr, rpg->pause_menu_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->pause_menu_spr, NULL);
    rpg->hand_selection_vect = (sfVector2f)
    {((rpg->pause_menu_vect.x + 425) + rpg->pause_menux),
    ((rpg->pause_menu_vect.y + 425) + rpg->pause_menuy)};
    sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->hand_selection_spr, NULL);
}

