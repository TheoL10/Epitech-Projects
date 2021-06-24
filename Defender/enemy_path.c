/*
** EPITECH PROJECT, 2021
** enemy_path
** File description:
** my_defender
*/

#include "include/my.h"
#include "include/struct.h"

void call_path8(defender_t *defender)
{
    if (defender->count_path2 == 9)
        defender->pos_mj.x += 10;
    if (defender->count_path2 == 9 && defender->pos_mj.x >= 1540) {
        sfSprite_setRotation(defender->mj, 0);
        defender->pos_mj.x += 50;
        defender->pos_mj.y -= 70;
        defender->count_path2 = 10;
    }
    if (defender->count_path2 == 10)
        defender->pos_mj.y += 10;
    if (defender->count_path2 == 10 && defender->pos_mj.y >= 1080) {
        defender->pos_mj.x = 930;
        defender->pos_mj.y = -150;
        defender->count_path2 = 0;
        defender->count_vie++;
    }
}

void call_path7(defender_t *defender)
{
    if (defender->count_path2 == 6)
        defender->pos_mj.y += 10;
    if (defender->count_path2 == 6 && defender->pos_mj.y >= 715) {
        sfSprite_setRotation(defender->mj, 90);
        defender->pos_mj.y += 30;
        defender->pos_mj.x += 30;
        defender->count_path2 = 7;
    } if (defender->count_path2 == 7)
        defender->pos_mj.x -= 10;
    if (defender->count_path2 == 7 && defender->pos_mj.x >= 700) {
        sfSprite_setRotation(defender->mj, 180);
        defender->pos_mj.x -= 50;
        defender->pos_mj.y += 50;
        defender->count_path2 = 8;
    } if (defender->count_path2 == 8)
        defender->pos_mj.y -= 10;
    if (defender->count_path2 == 8 && defender->pos_mj.y >= 315) {
        sfSprite_setRotation(defender->mj, -90);
        defender->pos_mj.x -= 80;
        defender->count_path2 = 9; }
}

void call_path6(defender_t *defender)
{
    if (defender->count_path2 == 3)
        defender->pos_mj.x += 10;
    if (defender->count_path2 == 3 && defender->pos_mj.x >= 1210) {
        sfSprite_setRotation(defender->mj, 180);
        defender->pos_mj.x += 105;
        defender->pos_mj.y += 20;
        defender->count_path2 = 4;
    }
    if (defender->count_path2 == 4)
        defender->pos_mj.y -= 10;
    if (defender->count_path2 == 4 && defender->pos_mj.y >= 515) {
        sfSprite_setRotation(defender->mj, 90);
        defender->pos_mj.y -= 80;
        defender->count_path2 = 5;
    } if (defender->count_path2 == 5)
        defender->pos_mj.x -= 10;
    if (defender->count_path2 == 5 && defender->pos_mj.x >= 1045) {
        sfSprite_setRotation(defender->mj, 0);
        defender->pos_mj.x -= 105;
        defender->count_path2 = 6; }
}

void call_path5(defender_t *defender)
{
    if (defender->count_path2 == 0)
        defender->pos_mj.y += 10;
    if (defender->count_path2 == 0 && defender->pos_mj.y >= 70) {
        sfSprite_setRotation(defender->mj, 90);
        defender->pos_mj.x += 60;
        defender->count_path2 = 1;
    }
    if (defender->count_path2 == 1)
        defender->pos_mj.x -= 10;
    if (defender->count_path2 == 1 && defender->pos_mj.x >= 370) {
        sfSprite_setRotation(defender->mj, 0);
        defender->pos_mj.x -= 80;
        defender->count_path2 = 2;
    } if (defender->count_path2 == 2)
        defender->pos_mj.y += 10;
    if (defender->count_path2 == 2 && defender->pos_mj.y >= 910) {
        sfSprite_setRotation(defender->mj, -90);
        defender->pos_mj.x -= 60;
        defender->pos_mj.y += 95;
        defender->count_path2 = 3; }
}

void call_path4(defender_t *defender)
{
    if (defender->count_path == 9)
        defender->pos_enemy.x += 10;
    if (defender->count_path == 9 && defender->pos_enemy.x >= 1540) {
        sfSprite_setRotation(defender->enemy, 0);
        defender->pos_enemy.x += 50;
        defender->pos_enemy.y -= 70;
        defender->count_path = 10;
    }
    if (defender->count_path == 10)
        defender->pos_enemy.y += 10;
    if (defender->count_path == 10 && defender->pos_enemy.y >= 1080) {
        defender->pos_enemy.x = 930;
        defender->pos_enemy.y = -150;
        defender->count_vie++;
        defender->count_path = 0;
    }
}