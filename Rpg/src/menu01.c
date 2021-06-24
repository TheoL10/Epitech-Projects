/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void init_main_menu(rpg_t *rpg)
{
    rpg->main_menu_bckg_spr = sfSprite_create();
    rpg->main_m_bckg_text = sfTexture_createFromFile("assets/mai.jpg", NULL);
    sfSprite_setTexture(rpg->main_menu_bckg_spr, rpg->main_m_bckg_text, sfTrue);
    rpg->hand_selection_spr = sfSprite_create();
    rpg->hand_s_text = sfTexture_createFromFile("assets/hand_selec.png", NULL);
    sfSprite_setTexture(rpg->hand_selection_spr, rpg->hand_s_text, sfTrue);
    rpg->hand_selection_vect = (sfVector2f) {362, 512};
    sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
    rpg->set_spr = sfSprite_create();
    rpg->set_text = sfTexture_createFromFile("assets/set.png", NULL);
    sfSprite_setTexture(rpg->set_spr, rpg->set_text, sfTrue);
    rpg->set_vect = (sfVector2f) {1800, 20};
    sfSprite_setPosition(rpg->set_spr, rpg->set_vect);
    rpg->htp_logo_spr = sfSprite_create();
    rpg->htp_logo_text = sfTexture_createFromFile("assets/htp.png", NULL);
    sfSprite_setTexture(rpg->htp_logo_spr, rpg->htp_logo_text, sfTrue);
    rpg->htp_logo_vect = (sfVector2f) {1800, 970};
    sfSprite_setPosition(rpg->htp_logo_spr, rpg->htp_logo_vect);
}

void init_set_menu(rpg_t *rpg)
{
    rpg->set_menu_spr = sfSprite_create();
    rpg->set_menu_text = sfTexture_createFromFile("assets/set_menu.png", NULL);
    sfSprite_setTexture(rpg->set_menu_spr, rpg->set_menu_text, sfTrue);
}

void display_main_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->main_menu_bckg_spr, NULL);
    sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->hand_selection_spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->set_spr, NULL);
    sfRenderWindow_drawSprite(rpg->window, rpg->htp_logo_spr, NULL);
}

void display_set_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->set_menu_spr, NULL);
    sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->hand_selection_spr, NULL);
}