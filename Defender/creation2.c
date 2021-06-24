/*
** EPITECH PROJECT, 2021
** creation2
** File description:
** creation2
*/

#include "include/my.h"
#include "include/struct.h"

void sprite2(defender_t *defender)
{
    defender->grass1 = sfSprite_create();
    defender->grass2 = sfSprite_create();
    defender->grass3 = sfSprite_create();
    defender->grass4 = sfSprite_create();
    defender->grass5 = sfSprite_create();
    defender->grass6 = sfSprite_create();
    defender->grass7 = sfSprite_create();
    defender->paus = sfSprite_create();
    defender->enemy = sfSprite_create();
    sfSprite_setScale(defender->enemy, (sfVector2f) {0.78, 0.78});
    defender->clock = sfClock_create();
    defender->resume = sfSprite_create();
    defender->menu = sfSprite_create();
    defender->esc = sfSprite_create();
    defender->vie1 = sfSprite_create();
    defender->vie2 = sfSprite_create();
    defender->vie3 = sfSprite_create();
    defender->fin = sfSprite_create();
    defender->shot = sfSprite_create();
    sprite3(defender);
}

void texture(defender_t *defender)
{
    defender->text_bg = sfTexture_createFromFile("tools/bg.png", NULL);
    defender->text_bg_menu = sfTexture_createFromFile("tools/m.png", NULL);
    defender->text_butt_play = sfTexture_createFromFile("tools/pla.png", NULL);
    defender->text_butt_back = sfTexture_createFromFile("tools/bac.png", NULL);
    defender->text_butt_sett = sfTexture_createFromFile("tools/set.png", NULL);
    defender->text_bg_sett = sfTexture_createFromFile("tools/bg_s.png", NULL);
    defender->text_arrow = sfTexture_createFromFile("tools/arrow.png", NULL);
    defender->text_butt_60 = sfTexture_createFromFile("tools/60.png", NULL);
    defender->text_butt_120 = sfTexture_createFromFile("tools/120.png", NULL);
    defender->text_butt_180 = sfTexture_createFromFile("tools/180.png", NULL);
    defender->text_cursor = sfTexture_createFromFile("tools/cursor.png", NULL);
    defender->text_twer1 = sfTexture_createFromFile("tools/tower1.png", NULL);
    defender->text_twer2 = sfTexture_createFromFile("tools/tower1.png", NULL);
    defender->text_twer3 = sfTexture_createFromFile("tools/tower1.png", NULL);
    defender->text_twer4 = sfTexture_createFromFile("tools/tower1.png", NULL);
    defender->text_twer5 = sfTexture_createFromFile("tools/tower1.png", NULL);
    defender->text_twer6 = sfTexture_createFromFile("tools/tower1.png", NULL);
    defender->text_twer7 = sfTexture_createFromFile("tools/tower1.png", NULL);
    texture2(defender);
}

void texture2(defender_t *defender)
{
    defender->text_grass1 = sfTexture_createFromFile("tools/grass1.png", NULL);
    defender->text_grass2 = sfTexture_createFromFile("tools/grass2.png", NULL);
    defender->text_grass3 = sfTexture_createFromFile("tools/grass3.png", NULL);
    defender->text_grass4 = sfTexture_createFromFile("tools/grass4.png", NULL);
    defender->text_grass5 = sfTexture_createFromFile("tools/grass5.png", NULL);
    defender->text_grass6 = sfTexture_createFromFile("tools/grass6.png", NULL);
    defender->text_grass7 = sfTexture_createFromFile("tools/grass7.png", NULL);
    defender->text_enemy = sfTexture_createFromFile("tools/spwk.png", NULL);
    defender->text_paus = sfTexture_createFromFile("tools/flou.png", NULL);
    defender->text_resume = sfTexture_createFromFile("tools/resume.png", NULL);
    defender->text_menu = sfTexture_createFromFile("tools/men.png", NULL);
    defender->text_esc = sfTexture_createFromFile("tools/escape.png", NULL);
    defender->text_vie1 = sfTexture_createFromFile("tools/vie3.png", NULL);
    defender->text_vie2 = sfTexture_createFromFile("tools/vie2.png", NULL);
    defender->text_vie3 = sfTexture_createFromFile("tools/vie1.png", NULL);
    defender->text_fin = sfTexture_createFromFile("tools/fin.png", NULL);
    defender->text_shot = sfTexture_createFromFile("tools/shotani.png", NULL);
    defender->text_shot2 = sfTexture_createFromFile("tools/shotani.png", NULL);
    defender->text_m_htp = sfTexture_createFromFile("tools/m_htp.png", NULL);
    texture3(defender);
}

void set_texture(defender_t *defender)
{
    sfSprite_setTexture(defender->bg, defender->text_bg, sfTrue);
    sfSprite_setTexture(defender->bg_menu, defender->text_bg_menu, sfTrue);
    sfSprite_setTexture(defender->butt_play, defender->text_butt_play, sfTrue);
    sfSprite_setTexture(defender->butt_back, defender->text_butt_back, sfTrue);
    sfSprite_setTexture(defender->butt_sett, defender->text_butt_sett, sfTrue);
    sfSprite_setTexture(defender->bg_sett, defender->text_bg_sett, sfTrue);
    sfSprite_setTexture(defender->arrow, defender->text_arrow, sfTrue);
    sfSprite_setTexture(defender->butt_60, defender->text_butt_60, sfTrue);
    sfSprite_setTexture(defender->butt_120, defender->text_butt_120, sfTrue);
    sfSprite_setTexture(defender->butt_180, defender->text_butt_180, sfTrue);
    sfSprite_setTexture(defender->cs, defender->text_cursor, sfTrue);
    sfSprite_setTexture(defender->twer1, defender->text_twer1, sfTrue);
    sfSprite_setTexture(defender->twer2, defender->text_twer2, sfTrue);
    sfSprite_setTexture(defender->twer3, defender->text_twer3, sfTrue);
    sfSprite_setTexture(defender->twer4, defender->text_twer4, sfTrue);
    sfSprite_setTexture(defender->twer5, defender->text_twer5, sfTrue);
    sfSprite_setTexture(defender->twer6, defender->text_twer6, sfTrue);
    sfSprite_setTexture(defender->twer7, defender->text_twer7, sfTrue);
    set_texture2(defender);
}

void set_texture2(defender_t *defender)
{
    sfSprite_setTexture(defender->grass1, defender->text_grass1, sfTrue);
    sfSprite_setTexture(defender->grass2, defender->text_grass2, sfTrue);
    sfSprite_setTexture(defender->grass3, defender->text_grass3, sfTrue);
    sfSprite_setTexture(defender->grass4, defender->text_grass4, sfTrue);
    sfSprite_setTexture(defender->grass5, defender->text_grass5, sfTrue);
    sfSprite_setTexture(defender->grass6, defender->text_grass6, sfTrue);
    sfSprite_setTexture(defender->grass7, defender->text_grass7, sfTrue);
    sfSprite_setTexture(defender->enemy, defender->text_enemy, sfTrue);
    defender->anim_enemy = (sfIntRect) {0, 0, 90, 160};
    sfSprite_setTexture(defender->paus, defender->text_paus, sfTrue);
    sfSprite_setTexture(defender->resume, defender->text_resume, sfTrue);
    sfSprite_setTexture(defender->menu, defender->text_menu, sfTrue);
    sfSprite_setTexture(defender->esc, defender->text_esc, sfTrue);
    sfSprite_setTexture(defender->vie1, defender->text_vie1, sfTrue);
    sfSprite_setTexture(defender->vie2, defender->text_vie2, sfTrue);
    sfSprite_setTexture(defender->vie3, defender->text_vie3, sfTrue);
    sfSprite_setTexture(defender->fin, defender->text_fin, sfTrue);
    defender->anim_shot = (sfIntRect) {0, 0, 170, 110};
    defender->anim_shot2 = (sfIntRect) {0, 0, 170, 110};
    set_texture3(defender);
}