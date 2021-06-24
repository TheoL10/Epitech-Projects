/*
** EPITECH PROJECT, 2021
** creation6
** File description:
** creation6
*/

#include "include/my.h"
#include "include/struct.h"

void set_texture5(defender_t *defender)
{
    sfSprite_setTexture(defender->sws2, defender->text_sws2, sfTrue);
    sfSprite_setTexture(defender->sws3, defender->text_sws3, sfTrue);
    sfSprite_setTexture(defender->sws4, defender->text_sws4, sfTrue);
    sfSprite_setTexture(defender->sws5, defender->text_sws5, sfTrue);
    sfSprite_setTexture(defender->sws6, defender->text_sws6, sfTrue);
    sfSprite_setTexture(defender->sws7, defender->text_sws7, sfTrue);
    defender->anim_ts = (sfIntRect) {0, 0, 533, 800};
    defender->anim_ts2 = (sfIntRect) {0, 0, 533, 800};
    defender->anim_ts3 = (sfIntRect) {0, 0, 533, 800};
    defender->anim_ts4 = (sfIntRect) {0, 0, 533, 800};
    defender->anim_ts5 = (sfIntRect) {0, 0, 533, 800};
    defender->anim_ts6 = (sfIntRect) {0, 0, 533, 800};
    defender->anim_ts7 = (sfIntRect) {0, 0, 533, 800};
    defender->anim_sws = (sfIntRect) {0, 0, 417, 400};
    defender->anim_sws2 = (sfIntRect) {0, 0, 417, 400};
    defender->anim_sws3 = (sfIntRect) {0, 0, 417, 400};
    defender->anim_sws4 = (sfIntRect) {0, 0, 417, 400};
    defender->anim_sws5 = (sfIntRect) {0, 0, 417, 400};
    defender->anim_sws6 = (sfIntRect) {0, 0, 417, 400};
    set_texture6(defender);
}

void set_position4(defender_t *defender)
{
    sfSprite_setPosition(defender->rock, defender->pos_rock);
    sfSprite_setPosition(defender->ts, defender->pos_ts);
    sfSprite_setPosition(defender->ts2, defender->pos_ts2);
    sfSprite_setPosition(defender->ts3, defender->pos_ts3);
    sfSprite_setPosition(defender->ts4, defender->pos_ts4);
    sfSprite_setPosition(defender->ts5, defender->pos_ts5);
    sfSprite_setPosition(defender->ts6, defender->pos_ts6);
    sfSprite_setPosition(defender->ts7, defender->pos_ts7);
    sfSprite_setPosition(defender->sws, defender->pos_sws);
    sfSprite_setPosition(defender->sws2, defender->pos_sws2);
    sfSprite_setPosition(defender->sws3, defender->pos_sws3);
    sfSprite_setPosition(defender->sws4, defender->pos_sws4);
    sfSprite_setPosition(defender->sws5, defender->pos_sws5);
    sfSprite_setPosition(defender->sws6, defender->pos_sws6);
    sfSprite_setPosition(defender->sws7, defender->pos_sws7);
    sfSprite_setPosition(defender->slt1, defender->pos_slt1);
    sfSprite_setPosition(defender->slt2, defender->pos_slt2);
    sfSprite_setPosition(defender->slt3, defender->pos_slt3);
    sfSprite_setPosition(defender->slt4, defender->pos_slt4);
    set_position5(defender);
}

void texture5(defender_t *defender)
{
    defender->text_slt3 = sfTexture_createFromFile("tools/select.png", NULL);
    defender->text_slt4 = sfTexture_createFromFile("tools/select.png", NULL);
    defender->text_up = sfTexture_createFromFile("tools/up.png", NULL);
    defender->text_mj = sfTexture_createFromFile("tools/mjsprite.png", NULL);
    defender->text_coin = sfTexture_createFromFile("tools/coin.png", NULL);
    defender->text_win = sfTexture_createFromFile("tools/m_win.png", NULL);
}

void set_texture6(defender_t *defender)
{
    defender->anim_sws7 = (sfIntRect) {0, 0, 417, 400};
    defender->anim_mj = (sfIntRect) {0, 0, 86, 89};
    sfSprite_setTexture(defender->slt1, defender->text_slt1, sfTrue);
    sfSprite_setTexture(defender->slt2, defender->text_slt2, sfTrue);
    sfSprite_setTexture(defender->slt3, defender->text_slt3, sfTrue);
    sfSprite_setTexture(defender->slt4, defender->text_slt4, sfTrue);
    sfSprite_setTexture(defender->up, defender->text_up, sfTrue);
    sfSprite_setTexture(defender->mj, defender->text_mj, sfTrue);
    sfSprite_setTexture(defender->coin, defender->text_coin, sfTrue);
    sfSprite_setTexture(defender->win, defender->text_win, sfTrue);
}

void sprite5(defender_t *defender)
{
    defender->clock2 = sfClock_create();
    defender->slt1 = sfSprite_create();
    defender->slt2 = sfSprite_create();
    defender->slt3 = sfSprite_create();
    defender->slt4 = sfSprite_create();
    defender->up = sfSprite_create();
    defender->mj = sfSprite_create();
    defender->coin = sfSprite_create();
    defender->win = sfSprite_create();
    defender->loop = sfMusic_createFromFile("tools/loop.ogg");
    defender->tower_sound = sfMusic_createFromFile("tools/boom.ogg");
    defender->tower_sound2 = sfMusic_createFromFile("tools/boom.ogg");
    defender->tower_sound3 = sfMusic_createFromFile("tools/boom.ogg");
    defender->tower_sound4 = sfMusic_createFromFile("tools/boom.ogg");
    defender->tower_sound5 = sfMusic_createFromFile("tools/boom.ogg");
    defender->tower_sound6 = sfMusic_createFromFile("tools/boom.ogg");
    defender->tower_sound7 = sfMusic_createFromFile("tools/boom.ogg");
    create_music_fromfile(defender);
}