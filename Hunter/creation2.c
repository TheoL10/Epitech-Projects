/*
** EPITECH PROJECT, 2020
** creation2
** File description:
** creation2
*/

#include "include/struct.h"
#include "include/my.h"

void draw_sprite2(hunter_t *hunter)
{
    if (hunter->menu == 2) {
        sfRenderWindow_clear(hunter->window, sfBlack);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_menu_s, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_butt_60, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_butt_12, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_butt_18, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_arrow, NULL);
        boom(hunter);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_mouse, NULL);
    }
}

void audio(hunter_t *hunter)
{
    hunter->boom = sfMusic_createFromFile("ressources/sound.ogg");
}