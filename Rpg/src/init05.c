/*
** EPITECH PROJECT, 2021
** init05
** File description:
** init05
*/

#include "../lib/my/my.h"

void init_item_inventory(rpg_t *rpg)
{
    rpg->coord_view = rpg->view;
    rpg->item_bob_lorenzo_spr = sfSprite_create();
    rpg->item_dollars_spr = sfSprite_create();
    rpg->item_wati_spr = sfSprite_create();
    rpg->item_bugatti_spr = sfSprite_create();
    rpg->item_ak_spr = sfSprite_create();
    rpg->item_alk_spr = sfSprite_create();
    rpg->item_bob_text = sfTexture_createFromFile("assets/bob.png", NULL);
    rpg->item_dollars_text = sfTexture_createFromFile("assets/dols.png", NULL);
    rpg->item_wati_text = sfTexture_createFromFile("assets/watib.png", NULL);
    rpg->item_bugatti_text = sfTexture_createFromFile("assets/vroum.png", NULL);
    rpg->item_ak_text = sfTexture_createFromFile("assets/ak.png", NULL);
    rpg->item_alk_text = sfTexture_createFromFile("assets/alk.png", NULL);
    sfSprite_setTexture(rpg->item_bob_lorenzo_spr, rpg->item_bob_text, sfTrue);
    sfSprite_setTexture(rpg->item_dollars_spr, rpg->item_dollars_text, sfTrue);
    sfSprite_setTexture(rpg->item_wati_spr, rpg->item_wati_text, sfTrue);
    sfSprite_setTexture(rpg->item_bugatti_spr, rpg->item_bugatti_text, sfTrue);
    sfSprite_setTexture(rpg->item_ak_spr, rpg->item_ak_text, sfTrue);
    sfSprite_setTexture(rpg->item_alk_spr, rpg->item_alk_text, sfTrue);
}

void init_end_menu(rpg_t *rpg)
{
    rpg->end_menu_spr = sfSprite_create();
    rpg->end_menu_text = sfTexture_createFromFile("assets/end_menu.png", NULL);
    sfSprite_setTexture(rpg->end_menu_spr, rpg->end_menu_text, sfTrue);
}