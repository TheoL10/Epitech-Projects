/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** my_defender
*/

#include "include/my.h"
#include "include/struct.h"

void music2(defender_t *defender)
{
    if (defender->count_zik1 == 1) {
        sfMusic_play(defender->tower_sound);
        defender->count_zik1 = 0;
    }
    if (defender->count_zik2 == 1) {
        sfMusic_play(defender->tower_sound2);
        defender->count_zik2 = 0;
    }
    if (defender->count_zik3 == 1) {
        sfMusic_play(defender->tower_sound3);
        defender->count_zik3 = 0;
    }
    if (defender->count_zik4 == 1) {
        sfMusic_play(defender->tower_sound4);
        defender->count_zik4 = 0;
    }
    if (defender->count_zik5 == 1) {
        sfMusic_play(defender->tower_sound5);
        defender->count_zik5 = 0;
    }
}

void music(defender_t *defender)
{
    if (defender->count_zik6 == 1) {
        sfMusic_play(defender->tower_sound6);
        defender->count_zik6 = 0;
    }
    if (defender->count_zik7 == 1) {
        sfMusic_play(defender->tower_sound7);
        defender->count_zik7 = 0;
    }
    music2(defender);
}

void game_func(defender_t *defender)
{
    enemy_path(defender);
    enemy_shot(defender);
    enemy_shot2(defender);
    enemy_shot3(defender);
    enemy_shot4(defender);
    enemy_shot5(defender);
    enemy_shot6(defender);
    enemy_shot7(defender);
    animation1(defender);
    if (defender->anim_shot6.left >= 1020)
        defender->anim_shot6.left = 0;
    if (defender->anim_shot7.left >= 1020)
        defender->anim_shot7.left = 0;
}

void call_clock(defender_t *defender)
{
    defender->time = sfClock_getElapsedTime(defender->clock);
    defender->time2 = sfClock_getElapsedTime(defender->clock2);
    defender->seconds = defender->time.microseconds / 800000.0;
    defender->seconds2 = defender->time2.microseconds / 800000.0;
    if (defender->count_menu == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->bg, NULL);
        sfText_setCharacterSize(defender->scoros, 96);
        defender->goldus = my_getnbrinverse(defender->gold, 0, 0, 0);
        sfText_setString(defender->scoros, defender->goldus);
    } draw_grass_second(defender);
    if (defender->seconds > 0.04) {
        if (defender->count_menu == 1) {
            game_func(defender);
        }
        set_texture_rect(defender);
        sfSprite_setTextureRect(defender->sws5, defender->anim_sws5);
        sfSprite_setTextureRect(defender->sws6, defender->anim_sws6);
        sfSprite_setTextureRect(defender->sws7, defender->anim_sws7);
        sfSprite_setTextureRect(defender->mj, defender->anim_mj);
    } second_clock(defender);
}

void game_loop(defender_t *defender)
{
    while (sfRenderWindow_isOpen(defender->window)) {
        while (sfRenderWindow_pollEvent(defender->window, &defender->event)) {
            if (defender->event.type == sfEvtClosed)
                sfRenderWindow_close(defender->window);
            if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
                sfRenderWindow_close(defender->window);
        }
    music(defender);
    call_clock(defender);
    set_position(defender);
    if (defender->count_fps == 0)
        sfRenderWindow_setFramerateLimit(defender->window, 60);
    menu(defender);
    sfRenderWindow_display(defender->window);
    }
}