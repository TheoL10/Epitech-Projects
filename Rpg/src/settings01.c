/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void select_120_fps(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 850
    && rpg->hand_selection_vect.y == 409) {
        sfRenderWindow_setFramerateLimit(rpg->window, 120);
    }
}

void select_volume_down(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 325
    && rpg->hand_selection_vect.y == 699 && rpg->volume > 0) {
        rpg->volume -= 10;
        sfMusic_setVolume(rpg->music_fond, rpg->volume);
    }
}

void select_volume_up(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 850
    && rpg->hand_selection_vect.y == 699 && rpg->volume < 100) {
        rpg->volume += 10;
        sfMusic_setVolume(rpg->music_fond, rpg->volume);
    }
}

void select_save_settings(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 325 && rpg->hand_selection_vect.y == 119)
        rpg->save_settings = 1;
}

void select_resize_screen(rpg_t *rpg)
{
    if (rpg->hand_selection_vect.x == 850 && rpg->hand_selection_vect.y == 119)
        sfRenderWindow_setSize(rpg->window, (sfVector2u) {960, 540});
}