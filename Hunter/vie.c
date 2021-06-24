/*
** EPITECH PROJECT, 2020
** vie
** File description:
** vie
*/

#include "include/my.h"
#include "include/struct.h"

void vie(hunter_t *hunter)
{
    if (hunter->vie == 1) {
        sfSprite_setPosition(hunter->sprite_v2, hunter->pos_v2);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_v2, NULL);
    }
    if (hunter->vie == 2) {
        sfSprite_setPosition(hunter->sprite_v1, hunter->pos_v1);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_v1, NULL);
    }
    if (hunter->vie == 3) {
        sfRenderWindow_clear(hunter->window, sfBlack);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_bg, NULL);
        hunter->menu = 3;
    }
}