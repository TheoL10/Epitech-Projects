/*
** EPITECH PROJECT, 2021
** creation4
** File description:
** creation4
*/

#include "include/my.h"
#include "include/struct.h"

void set_position3(defender_t *defender)
{
    sfSprite_setPosition(defender->shot3, defender->pos_shot3);
    sfSprite_setPosition(defender->shot4, defender->pos_shot4);
    sfSprite_setPosition(defender->shot5, defender->pos_shot5);
    sfSprite_setPosition(defender->shot6, defender->pos_shot6);
    sfSprite_setPosition(defender->shot7, defender->pos_shot7);
    sfSprite_setPosition(defender->tesla1, defender->pos_tesla1);
    sfSprite_setPosition(defender->tesla2, defender->pos_tesla2);
    sfSprite_setPosition(defender->tesla3, defender->pos_tesla3);
    sfSprite_setPosition(defender->tesla4, defender->pos_tesla4);
    sfSprite_setPosition(defender->tesla5, defender->pos_tesla5);
    sfSprite_setPosition(defender->tesla6, defender->pos_tesla6);
    sfSprite_setPosition(defender->tesla7, defender->pos_tesla7);
    sfSprite_setPosition(defender->slow1, defender->pos_slow1);
    sfSprite_setPosition(defender->slow2, defender->pos_slow2);
    sfSprite_setPosition(defender->slow3, defender->pos_slow3);
    sfSprite_setPosition(defender->slow4, defender->pos_slow4);
    sfSprite_setPosition(defender->slow5, defender->pos_slow5);
    sfSprite_setPosition(defender->slow6, defender->pos_slow6);
    sfSprite_setPosition(defender->slow7, defender->pos_slow7);
    set_position4(defender);
}

void position6(defender_t *defender)
{
    defender->origin_shot3.x = 73;
    defender->origin_shot3.y = 46;
    defender->origin_shot4.x = 73;
    defender->origin_shot4.y = 46;
    defender->origin_shot5.x = 73;
    defender->origin_shot5.y = 46;
    defender->origin_shot6.x = 73;
    defender->origin_shot6.y = 46;
    defender->origin_shot7.x = 73;
    defender->origin_shot7.y = 46;
    defender->pos_tesla1.x = 430;
    defender->pos_tesla1.y = 270;
    defender->pos_tesla2.x = 770;
    defender->pos_tesla2.y = 410;
    defender->pos_tesla3.x = 760;
    defender->pos_tesla3.y = 600;
    defender->pos_tesla4.x = 430;
    defender->pos_tesla4.y = 800;
    defender->pos_tesla5.x = 1080;
    position7(defender);
}

void position5(defender_t *defender)
{
    defender->pos_m_build.x = 1678;
    defender->pos_m_build.y = 300;
    defender->pos_shot3.x = 805;
    defender->pos_shot3.y = 650;
    defender->pos_shot4.x = 485;
    defender->pos_shot4.y = 800;
    defender->pos_shot5.x = 1130;
    defender->pos_shot5.y = 600;
    defender->pos_shot6.x = 1465;
    defender->pos_shot6.y = 450;
    defender->pos_shot7.x = 1130;
    defender->pos_shot7.y = 850;
    position6(defender);
}

void set_texture4(defender_t *defender)
{
    sfSprite_setTexture(defender->tesla5, defender->text_tesla5, sfTrue);
    sfSprite_setTexture(defender->tesla6, defender->text_tesla6, sfTrue);
    sfSprite_setTexture(defender->tesla7, defender->text_tesla7, sfTrue);
    sfSprite_setTexture(defender->slow1, defender->text_slow1, sfTrue);
    sfSprite_setTexture(defender->slow2, defender->text_slow2, sfTrue);
    sfSprite_setTexture(defender->slow3, defender->text_slow3, sfTrue);
    sfSprite_setTexture(defender->slow4, defender->text_slow4, sfTrue);
    sfSprite_setTexture(defender->slow5, defender->text_slow5, sfTrue);
    sfSprite_setTexture(defender->slow6, defender->text_slow6, sfTrue);
    sfSprite_setTexture(defender->slow7, defender->text_slow7, sfTrue);
    sfSprite_setTexture(defender->rock, defender->text_rock, sfTrue);
    sfSprite_setTexture(defender->ts, defender->text_ts, sfTrue);
    sfSprite_setTexture(defender->ts2, defender->text_ts2, sfTrue);
    sfSprite_setTexture(defender->ts3, defender->text_ts3, sfTrue);
    sfSprite_setTexture(defender->ts4, defender->text_ts4, sfTrue);
    sfSprite_setTexture(defender->ts5, defender->text_ts5, sfTrue);
    sfSprite_setTexture(defender->ts6, defender->text_ts6, sfTrue);
    sfSprite_setTexture(defender->ts7, defender->text_ts7, sfTrue);
    sfSprite_setTexture(defender->sws, defender->text_sws, sfTrue);
    set_texture5(defender);
}

void sprite4(defender_t *defender)
{
    defender->slow4 = sfSprite_create();
    defender->slow5 = sfSprite_create();
    defender->slow6 = sfSprite_create();
    defender->slow7 = sfSprite_create();
    defender->rock = sfSprite_create();
    defender->ts = sfSprite_create();
    defender->ts2 = sfSprite_create();
    defender->ts3 = sfSprite_create();
    defender->ts4 = sfSprite_create();
    defender->ts5 = sfSprite_create();
    defender->ts6 = sfSprite_create();
    defender->ts7 = sfSprite_create();
    defender->sws = sfSprite_create();
    defender->sws2 = sfSprite_create();
    defender->sws3 = sfSprite_create();
    defender->sws4 = sfSprite_create();
    defender->sws5 = sfSprite_create();
    defender->sws6 = sfSprite_create();
    defender->sws7 = sfSprite_create();
    sprite5(defender);
}