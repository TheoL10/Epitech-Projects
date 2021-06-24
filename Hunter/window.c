/*
** EPITECH PROJECT, 2020
** window
** File description:
** window
*/

#include "include/my.h"
#include "include/struct.h"

void window_game(hunter_t *hunter)
{
    sfSprite_setPosition(hunter->sprite_bird, hunter->pos);
    sfSprite_setPosition(hunter->sprite_bm, (sfVector2f) {hunter->ms.x - 87,
                                                        hunter->ms.y - 87});
    sfSprite_setPosition(hunter->sprite_v3, hunter->pos_v3);
    move_sprite(hunter);
    animation(hunter);
}