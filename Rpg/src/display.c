/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void display_character(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->character_spr, rpg->character_rect);
    sfSprite_setPosition(rpg->character_spr, rpg->character_vect);
    sfRenderWindow_drawSprite(rpg->window, rpg->character_spr, NULL);
}

void character_clock(rpg_t *rpg)
{
    rpg->character_time = sfClock_getElapsedTime(rpg->character_clock);
    rpg->character_seconds = rpg->character_time.microseconds / 1000000.0;
    if (rpg->character_seconds > 0.04) {
        if (rpg->walk_backward == 1 || rpg->walk_toward == 1
        || rpg->walk_left == 1 || rpg->walk_right == 1) {
            rpg->character_rect.left += 64;
            if (rpg->character_rect.left >= 125)
                rpg->character_rect.left = 0;
        }
        sfClock_restart(rpg->character_clock);
    }
}