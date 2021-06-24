/*
** EPITECH PROJECT, 2021
** init02
** File description:
** init02
*/

#include "../lib/my/my.h"

void init_speech(rpg_t *rpg)
{
    rpg->coord_view = rpg->view;
    rpg->speech_spr = sfSprite_create();
    rpg->speech_text = sfTexture_createFromFile("assets/speech.png", NULL);
    sfSprite_setTexture(rpg->speech_spr, rpg->speech_text, sfTrue);
}

void init_inventory(rpg_t *rpg)
{
    rpg->coord_view = rpg->view;
    rpg->inventory_spr = sfSprite_create();
    rpg->select_spr = sfSprite_create();
    rpg->inventory_text = sfTexture_createFromFile("assets/inv.png", NULL);
    rpg->select_text =
    sfTexture_createFromFile("assets/logo_select.png", NULL);
    sfSprite_setTexture(rpg->select_spr, rpg->select_text, sfTrue);
    sfSprite_setTexture(rpg->inventory_spr, rpg->inventory_text, sfTrue);
}

void init_htp_menu(rpg_t *rpg)
{
    rpg->htp_menu_spr = sfSprite_create();
    rpg->htp_menu_text =
    sfTexture_createFromFile("assets/menu_htp.png", NULL);
    sfSprite_setTexture(rpg->htp_menu_spr, rpg->htp_menu_text, sfTrue);
}

void init_menu_combat_alde(rpg_t *rpg)
{
    rpg->coord_view = rpg->view;
    rpg->menu_combat_alde_spr = sfSprite_create();
    rpg->menu_combat_alde_text =
    sfTexture_createFromFile("assets/menu_combat_alde.png", NULL);
    sfSprite_setTexture(rpg->menu_combat_alde_spr,
    rpg->menu_combat_alde_text, sfTrue);
}

void init_menu_combat_jason(rpg_t *rpg)
{
    rpg->coord_view = rpg->view;
    rpg->menu_combat_jason_spr = sfSprite_create();
    rpg->menu_combat_jason_text =
    sfTexture_createFromFile("assets/menu_combat_jason.png", NULL);
    sfSprite_setTexture(rpg->menu_combat_jason_spr,
    rpg->menu_combat_jason_text, sfTrue);
}