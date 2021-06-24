/*
** EPITECH PROJECT, 2020
** position
** File description:
** position
*/

#include "include/my.h"
#include "include/struct.h"

void position(runner_t *run)
{
    run->pos_para2.y = -110;
    run->pos_player.x = 10;
    run->pos_player.y = 700;
    run->pos_play.x = 830;
    run->pos_play.y = 420;
    run->pos_set.x = 830;
    run->pos_set.y = 700;
    run->pos_back.x = 830;
    run->pos_back.y = 560;
    run->pos_ennemy.x = 1800;
    run->pos_ennemy.y = 790;
    run->pos_life3.x = 1470;
    run->pos_life3.y = 25;
    run->pos_life2.x = 1470;
    run->pos_life2.y = 25;
    run->pos_life1.x = 1470;
    run->pos_life1.y = 25;
    position2(run);
}

void position2(runner_t *run)
{
    run->pos_fps1.x = 383;
    run->pos_fps1.y = 500;
    run->pos_fps2.x = 783;
    run->pos_fps2.y = 500;
    run->pos_fps3.x = 1183;
    run->pos_fps3.y = 500;
    run->pos_score1.x = 450;
    run->pos_score1.y = 83;
    run->pos_score2.x = 400;
    run->pos_score2.y = 83;
    run->pos_score3.x = 350;
    run->pos_score3.y = 83;
}