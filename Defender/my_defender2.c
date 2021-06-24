/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** my_defender
*/

#include "include/my.h"
#include "include/struct.h"

void draw_grass_second(defender_t *defender)
{
    if (defender->count_menu == 1 && defender->third == 1)
        sfRenderWindow_drawSprite(defender->window, defender->grass1, NULL);
    if (defender->count_menu == 1 && defender->third2 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->grass3, NULL);
    if (defender->count_menu == 1 && defender->third3 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->grass4, NULL);
    if (defender->count_menu == 1 && defender->third4 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->grass2, NULL);
    if (defender->count_menu == 1 && defender->third5 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->grass6, NULL);
    if (defender->count_menu == 1 && defender->third6 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->grass5, NULL);
    if (defender->count_menu == 1 && defender->third7 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->grass7, NULL);
}

void second_clock(defender_t *defender)
{
    if (defender->seconds2 > 0.8) {
        if (defender->second == 1 || defender->second2 == 1 ||
        defender->second3 == 1 || defender->second4 == 1 ||
        defender->second5 == 1 || defender->second6 == 1 ||
        defender->second7 == 1)
            sfMusic_play(defender->ts_sound);
        cond_third(defender);
        if (defender->count_menu == 1 && defender->third6 == 1) {
            sfMusic_play(defender->sws_sound6);
            sfRenderWindow_drawSprite(defender->window, defender->sws6, NULL);
        }
        if (defender->count_menu == 1 && defender->third7 == 1) {
            sfMusic_play(defender->sws_sound7);
            sfRenderWindow_drawSprite(defender->window, defender->sws7, NULL);
        }
        sfClock_restart(defender->clock2);
    }
}

void cond_third(defender_t *defender)
{
    if (defender->count_menu == 1 && defender->third == 1) {
        sfMusic_play(defender->sws_sound);
        sfRenderWindow_drawSprite(defender->window, defender->sws, NULL);
    }
    if (defender->count_menu == 1 && defender->third2 == 1) {
        sfMusic_play(defender->sws_sound2);
        sfRenderWindow_drawSprite(defender->window, defender->sws2, NULL);
    }
    if (defender->count_menu == 1 && defender->third3 == 1) {
        sfMusic_play(defender->sws_sound3);
        sfRenderWindow_drawSprite(defender->window, defender->sws3, NULL);
    }
    if (defender->count_menu == 1 && defender->third4 == 1) {
        sfMusic_play(defender->sws_sound4);
        sfRenderWindow_drawSprite(defender->window, defender->sws4, NULL);
    }
    if (defender->count_menu == 1 && defender->third5 == 1) {
        sfMusic_play(defender->sws_sound5);
        sfRenderWindow_drawSprite(defender->window, defender->sws5, NULL);
    }
}

void set_texture_rect(defender_t *defender)
{
    sfSprite_setTextureRect(defender->enemy, defender->anim_enemy);
    sfSprite_setTextureRect(defender->shot, defender->anim_shot);
    sfSprite_setTextureRect(defender->shot2, defender->anim_shot2);
    sfSprite_setTextureRect(defender->shot3, defender->anim_shot3);
    sfSprite_setTextureRect(defender->shot4, defender->anim_shot4);
    sfSprite_setTextureRect(defender->shot5, defender->anim_shot5);
    sfSprite_setTextureRect(defender->shot6, defender->anim_shot6);
    sfSprite_setTextureRect(defender->shot7, defender->anim_shot7);
    sfSprite_setTextureRect(defender->ts, defender->anim_ts);
    sfSprite_setTextureRect(defender->ts2, defender->anim_ts2);
    sfSprite_setTextureRect(defender->ts3, defender->anim_ts3);
    sfSprite_setTextureRect(defender->ts4, defender->anim_ts4);
    sfSprite_setTextureRect(defender->ts5, defender->anim_ts5);
    sfSprite_setTextureRect(defender->ts6, defender->anim_ts6);
    sfSprite_setTextureRect(defender->ts7, defender->anim_ts7);
    sfClock_restart(defender->clock);
    sfSprite_setTextureRect(defender->sws, defender->anim_sws);
    sfSprite_setTextureRect(defender->sws2, defender->anim_sws2);
    sfSprite_setTextureRect(defender->sws3, defender->anim_sws3);
    sfSprite_setTextureRect(defender->sws4, defender->anim_sws4);
}