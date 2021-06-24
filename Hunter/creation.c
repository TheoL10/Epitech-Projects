/*
** EPITECH PROJECT, 2020
** creation
** File description:
** creation
*/

#include "include/struct.h"
#include "include/my.h"

void sprite(hunter_t *hunter)
{
    hunter->sprite_fond = sfSprite_create();
    hunter->sprite_bird = sfSprite_create();
    hunter->sprite_mouse = sfSprite_create();
    hunter->sprite_bm = sfSprite_create();
    hunter->sprite_menu = sfSprite_create();
    hunter->sprite_butt_p = sfSprite_create();
    hunter->sprite_butt_b = sfSprite_create();
    hunter->sprite_butt_s = sfSprite_create();
    hunter->sprite_v3 = sfSprite_create();
    hunter->sprite_v2 = sfSprite_create();
    hunter->sprite_v1 = sfSprite_create();
    hunter->sprite_bg = sfSprite_create();
    hunter->sprite_menu_s = sfSprite_create();
    hunter->sprite_butt_60 = sfSprite_create();
    hunter->sprite_butt_12 = sfSprite_create();
    hunter->sprite_butt_18 = sfSprite_create();
    hunter->sprite_arrow = sfSprite_create();
}

void texture(texture_hunter_t *hunter)
{
    hunter->text_fond = sfTexture_createFromFile("ressources/Fond.png", NULL);
    hunter->text_bird = sfTexture_createFromFile("ressources/Lorenz.png", NULL);
    hunter->text_mouse = sfTexture_createFromFile("ressources/mouse.jpg", NULL);
    hunter->text_boom = sfTexture_createFromFile("ressources/boom.png", NULL);
    hunter->text_menu = sfTexture_createFromFile("ressources/menu.png", NULL);
    hunter->text_but_p = sfTexture_createFromFile("ressources/but.png", NULL);
    hunter->text_but_b = sfTexture_createFromFile("ressources/bu.png", NULL);
    hunter->text_but_s = sfTexture_createFromFile("ressources/b.png", NULL);
    hunter->text_v3 = sfTexture_createFromFile("ressources/v3.png", NULL);
    hunter->text_v2 = sfTexture_createFromFile("ressources/v2.png", NULL);
    hunter->text_v1 = sfTexture_createFromFile("ressources/v1.png", NULL);
    hunter->text_bg = sfTexture_createFromFile("ressources/fin.png", NULL);
    hunter->text_men_s = sfTexture_createFromFile("ressources/me_s.png", NULL);
    hunter->text_b_60 = sfTexture_createFromFile("ressources/60.png", NULL);
    hunter->text_b_2 = sfTexture_createFromFile("ressources/12.png", NULL);
    hunter->text_b_8 = sfTexture_createFromFile("ressources/18.png", NULL);
    hunter->text_arrow = sfTexture_createFromFile("ressources/flech.png", NULL);
}

void set_texture(hunter_t *hunter, texture_hunter_t *text_hunter)
{
    sfSprite_setTexture(hunter->sprite_menu, text_hunter->text_menu, sfTrue);
    sfSprite_setTexture(hunter->sprite_butt_p, text_hunter->text_but_p, sfTrue);
    sfSprite_setTexture(hunter->sprite_butt_b, text_hunter->text_but_b, sfTrue);
    sfSprite_setTexture(hunter->sprite_butt_s, text_hunter->text_but_s, sfTrue);
    sfSprite_setTexture(hunter->sprite_fond, text_hunter->text_fond, sfTrue);
    sfSprite_setTexture(hunter->sprite_bird, text_hunter->text_bird, sfTrue);
    sfSprite_setTexture(hunter->sprite_mouse, text_hunter->text_mouse, sfTrue);
    sfSprite_setTexture(hunter->sprite_bm, text_hunter->text_boom, sfTrue);
    sfSprite_setTexture(hunter->sprite_v3, text_hunter->text_v3, sfTrue);
    sfSprite_setTexture(hunter->sprite_v2, text_hunter->text_v2, sfTrue);
    sfSprite_setTexture(hunter->sprite_v1, text_hunter->text_v1, sfTrue);
    sfSprite_setTexture(hunter->sprite_bg, text_hunter->text_bg, sfTrue);
    sfSprite_setTexture(hunter->sprite_menu_s, text_hunter->text_men_s, sfTrue);
    sfSprite_setTexture(hunter->sprite_butt_60, text_hunter->text_b_60, sfTrue);
    sfSprite_setTexture(hunter->sprite_butt_12, text_hunter->text_b_2, sfTrue);
    sfSprite_setTexture(hunter->sprite_butt_18, text_hunter->text_b_8, sfTrue);
    sfSprite_setTexture(hunter->sprite_arrow, text_hunter->text_arrow, sfTrue);
    sfSprite_setTextureRect(hunter->sprite_bird, hunter->bird);
}

void clock(hunter_t *hunter)
{
    hunter->clock = sfClock_create();
    hunter->move = sfClock_create();
}

void draw_sprite(hunter_t *hunter)
{
    if (hunter->menu == 0) {
        sfRenderWindow_clear(hunter->window, sfBlack);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_menu, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_butt_p, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_butt_b, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_butt_s, NULL);
        boom(hunter);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_mouse, NULL);
    }
    if (hunter->menu == 1) {
        sfRenderWindow_clear(hunter->window, sfBlack);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_fond, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_bird, NULL);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_v3, NULL);
        boom(hunter);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_mouse, NULL);
    }
    draw_sprite2(hunter);
}