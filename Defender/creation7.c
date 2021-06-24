/*
** EPITECH PROJECT, 2021
** creation7
** File description:
** creation7
*/

#include "include/my.h"
#include "include/struct.h"

void create_music_fromfile(defender_t *defender)
{
    defender->ts_sound = sfMusic_createFromFile("tools/zz_zz.ogg");
    defender->ts_sound2 = sfMusic_createFromFile("tools/zz_zz.ogg");
    defender->ts_sound3 = sfMusic_createFromFile("tools/zz_zz.ogg");
    defender->ts_sound4 = sfMusic_createFromFile("tools/zz_zz.ogg");
    defender->ts_sound5 = sfMusic_createFromFile("tools/zz_zz.ogg");
    defender->ts_sound6 = sfMusic_createFromFile("tools/zz_zz.ogg");
    defender->ts_sound7 = sfMusic_createFromFile("tools/zz_zz.ogg");
    defender->sws_sound = sfMusic_createFromFile("tools/sleep.ogg");
    defender->sws_sound2 = sfMusic_createFromFile("tools/sleep.ogg");
    defender->sws_sound3 = sfMusic_createFromFile("tools/sleep.ogg");
    defender->sws_sound4 = sfMusic_createFromFile("tools/sleep.ogg");
    defender->sws_sound5 = sfMusic_createFromFile("tools/sleep.ogg");
    defender->sws_sound6 = sfMusic_createFromFile("tools/sleep.ogg");
    defender->sws_sound7 = sfMusic_createFromFile("tools/sleep.ogg");
}

void position10(defender_t *defender)
{
    defender->pos_mj.x = 930;
    defender->pos_mj.y = 150;
    defender->pos_coin.x = 690;
    defender->pos_coin.y = 8;
}

void set_position5(defender_t *defender)
{
    sfSprite_setPosition(defender->mj, defender->pos_mj);
    sfSprite_setPosition(defender->coin, defender->pos_coin);
}