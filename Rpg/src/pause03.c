/*
** EPITECH PROJECT, 2021
** pause03
** File description:
** pause03
*/

#include "../lib/my/my.h"

void select_main_menu_button(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == (rpg->pause_menu_vect.x + 425)) {
        rpg->pause_menu = 0;
        rpg->main_menu = 1;
        rpg->save_coord_view = rpg->view;
        rpg->view = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
        sfRenderWindow_setView(rpg->window, rpg->view);
        rpg->hand_selection_vect = (sfVector2f) {362, 512};
        sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
        rpg->back_from_pause_menu = 1;
    }
}

void select_quit_pause_button(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == (rpg->pause_menu_vect.x + 925)) {
        sfRenderWindow_close(rpg->window);
    }
}

void select_settings_pause_button(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == (rpg->pause_menu_vect.x + 1595)) {
        rpg->pause_menu = 0;
        rpg->if_in_pause_menu = 1;
        rpg->main_menu = 2;
        rpg->save_coord_view = rpg->view;
        rpg->view = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
        sfRenderWindow_setView(rpg->window, rpg->view);
        rpg->hand_selection_vect = (sfVector2f) {20, 9};
        sfSprite_setPosition(rpg->hand_selection_spr, rpg->hand_selection_vect);
        rpg->back_from_pause_menu = 1;
    }
}