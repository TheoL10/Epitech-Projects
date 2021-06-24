/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** my_hunter
*/

#include "include/struct.h"
#include "include/my.h"

void move_sprite(hunter_t *hunter)
{
    hunter->movetime = sfClock_getElapsedTime(hunter->move);
    hunter->movefloat = hunter->movetime.microseconds / 1000000.0;
    hunter->pos.x += hunter->acceleration + 600 * hunter->movefloat;

    if (hunter->pos.x >= 1920) {
        hunter->pos.x = -390;
        hunter->pos.y = rand() % 900;
        hunter->vie++;
    }
    miss_click(hunter);
    vie(hunter);
    kill_bird(hunter);
    sfClock_restart(hunter->move);
}

void animation(hunter_t *hunter)
{
    hunter->time = sfClock_getElapsedTime(hunter->clock);
    hunter->seconds = hunter->time.microseconds / 1000000.0;
    if (hunter->seconds > 0.1) {
        hunter->bird.left += 62;
        if (hunter->bird.left >= 185)
            hunter->bird.left = 0;
        sfClock_restart(hunter->clock);
        sfSprite_setTextureRect(hunter->sprite_bird, hunter->bird);
    }
}

void kill_bird(hunter_t *hunter)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
    && hunter->ms.x <= hunter->pos.x + 153
    && hunter->ms.x >= hunter->pos.x
    && hunter->ms.y <= hunter->pos.y + 134
    && hunter->ms.y >= hunter->pos.y) {
        sfMusic_play(hunter->boom);
        hunter->pos.x = -500;
        hunter->pos.y = rand() % 800;
        hunter->acceleration += 0.5;
        hunter->count += 100;
        hunter->life++;
    }
}

void boom(hunter_t *hunter)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_play(hunter->boom);
        sfRenderWindow_drawSprite(hunter->window, hunter->sprite_bm, NULL);
    }
}

void game_loop(hunter_t *hunter, texture_hunter_t *text_hunter)
{
    while (sfRenderWindow_isOpen(hunter->window)) {
        while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
            if (hunter->event.type == sfEvtClosed)
                sfRenderWindow_close(hunter->window);
            if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
                sfRenderWindow_close(hunter->window);
            }
        mouse_action(hunter);
        draw_sprite(hunter);
        menu(hunter);
        sfRenderWindow_setMouseCursorVisible(hunter->window, sfFalse);
        sfRenderWindow_display(hunter->window);
    }
    kill_game(hunter, text_hunter);
}