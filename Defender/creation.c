/*
** EPITECH PROJECT, 2021
** creation
** File description:
** creation
*/

#include "include/my.h"
#include "include/struct.h"

void position(defender_t *defender)
{
    defender->pos_butt_play.x = 830;
    defender->pos_butt_play.y = 500;
    defender->pos_butt_back.x = 830;
    defender->pos_butt_back.y = 640;
    defender->pos_butt_sett.x = 830;
    defender->pos_butt_sett.y = 780;
    defender->pos_arrow.x = 0;
    defender->pos_arrow.y = 0;
    defender->pos_butt_60.x = 383;
    defender->pos_butt_60.y = 500;
    defender->pos_butt_12O.x = 783;
    defender->pos_butt_12O.y = 500;
    defender->pos_butt_180.x = 1183;
    defender->pos_butt_180.y = 500;
    defender->pos_enemy.x = 930;
    defender->pos_enemy.y = -150;
    position2(defender);
}

void position2(defender_t *defender)
{
    defender->pos_twer1.x = 470;
    defender->pos_twer1.y = 270;
    defender->pos_twer2.x = 800;
    defender->pos_twer2.y = 420;
    defender->pos_twer3.x = 790;
    defender->pos_twer3.y = 650;
    defender->pos_twer4.x = 470;
    defender->pos_twer4.y = 800;
    defender->pos_twer5.x = 1115;
    defender->pos_twer5.y = 600;
    defender->pos_twer6.x = 1450;
    defender->pos_twer6.y = 450;
    defender->pos_twer7.x = 1115;
    defender->pos_twer7.y = 850;
    defender->origin.x = 100;
    defender->origin.y = 81;
    position3(defender);
}

void position3(defender_t *defender)
{
    defender->pos_grass1.x = 414;
    defender->pos_grass1.y = 213;
    defender->pos_grass2.x = 414;
    defender->pos_grass2.y = 807;
    defender->pos_grass3.x = 750;
    defender->pos_grass3.y = 369;
    defender->pos_grass4.x = 750;
    defender->pos_grass4.y = 609;
    defender->pos_grass5.x = 1385;
    defender->pos_grass5.y = 369;
    defender->pos_grass6.x = 1066;
    defender->pos_grass6.y = 556;
    defender->pos_grass7.x = 1066;
    defender->pos_grass7.y = 807;
    defender->pos_resume.x = 830;
    defender->pos_resume.y = 500;
    defender->pos_menu.x = 550;
    defender->pos_menu.y = 500;
    position4(defender);
}

void position4(defender_t *defender)
{
    defender->pos_esc.x = 1110;
    defender->pos_esc.y = 500;
    defender->pos_vie1.x = 1470;
    defender->pos_vie1.y = 25;
    defender->pos_vie2.x = 1470;
    defender->pos_vie2.y = 25;
    defender->pos_vie3.x = 1470;
    defender->pos_vie3.y = 25;
    defender->pos_shot.x = 485;
    defender->pos_shot.y = 270;
    defender->origin_shot.x = 73;
    defender->origin_shot.y = 46;
    defender->pos_shot2.x = 815;
    defender->pos_shot2.y = 420;
    defender->origin_shot2.x = 73;
    defender->origin_shot2.y = 46;
    defender->pos_htp.x = 1810;
    defender->pos_htp.y = 880;
    position5(defender);
}

void sprite(defender_t *defender)
{
    defender->bg = sfSprite_create();
    defender->bg_menu = sfSprite_create();
    defender->butt_play = sfSprite_create();
    defender->butt_back = sfSprite_create();
    defender->butt_sett = sfSprite_create();
    defender->bg_sett = sfSprite_create();
    defender->arrow = sfSprite_create();
    defender->butt_60 = sfSprite_create();
    defender->butt_120 = sfSprite_create();
    defender->butt_180 = sfSprite_create();
    defender->cs = sfSprite_create();
    defender->twer1 = sfSprite_create();
    defender->twer2 = sfSprite_create();
    defender->twer3 = sfSprite_create();
    defender->twer4 = sfSprite_create();
    defender->twer5 = sfSprite_create();
    defender->twer6 = sfSprite_create();
    defender->twer7 = sfSprite_create();
    sprite2(defender);
}