/*
** EPITECH PROJECT, 2020
** set_position
** File description:
** set_position
*/

#include "include/my.h"
#include "include/struct.h"

void set_position_menu1(hunter_t *hunter)
{
    sfSprite_setPosition(hunter->sprite_butt_p, hunter->pos_butt_p);
    sfSprite_setPosition(hunter->sprite_butt_b, hunter->pos_butt_b);
    sfSprite_setPosition(hunter->sprite_butt_s, hunter->pos_butt_s);
    sfSprite_setPosition(hunter->sprite_bm, (sfVector2f) {hunter->ms.x - 87,
                                                        hunter->ms.y - 87});
}

void set_position_menu2(hunter_t *hunter)
{
    sfSprite_setPosition(hunter->sprite_butt_60, hunter->pos_butt_60);
    sfSprite_setPosition(hunter->sprite_butt_12, hunter->pos_butt_120);
    sfSprite_setPosition(hunter->sprite_butt_18, hunter->pos_butt_180);
    sfSprite_setPosition(hunter->sprite_bm, (sfVector2f) {hunter->ms.x - 87,
                                                        hunter->ms.y - 87});
}