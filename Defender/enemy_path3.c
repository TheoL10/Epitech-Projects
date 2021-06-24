/*
** EPITECH PROJECT, 2021
** enemy_path3
** File description:
** enemy_path3
*/

#include "include/my.h"
#include "include/struct.h"

void call_path9(defender_t *defender)
{
    if (defender->count_path == 2 && defender->pos_enemy.y == 910) {
        sfSprite_setRotation(defender->enemy, -90);
        defender->pos_enemy.x -= 60;
        defender->pos_enemy.y += 95;
        defender->count_path = 3; }
}

void call_path3(defender_t *defender)
{
    if (defender->count_path == 6)
        defender->pos_enemy.y += 10;
    if (defender->count_path == 6 && defender->pos_enemy.y == 715) {
        sfSprite_setRotation(defender->enemy, 90);
        defender->pos_enemy.y += 30;
        defender->pos_enemy.x += 30;
        defender->count_path = 7;
    } if (defender->count_path == 7)
        defender->pos_enemy.x -= 10;
    if (defender->count_path == 7 && defender->pos_enemy.x == 700) {
        sfSprite_setRotation(defender->enemy, 180);
        defender->pos_enemy.x -= 50;
        defender->pos_enemy.y += 50;
        defender->count_path = 8;
    } if (defender->count_path == 8)
        defender->pos_enemy.y -= 10;
    if (defender->count_path == 8 && defender->pos_enemy.y == 315) {
        sfSprite_setRotation(defender->enemy, -90);
        defender->pos_enemy.x -= 80;
        defender->count_path = 9; }
}

void call_path2(defender_t *defender)
{
    if (defender->count_path == 3)
        defender->pos_enemy.x += 10;
    if (defender->count_path == 3 && defender->pos_enemy.x == 1210) {
        sfSprite_setRotation(defender->enemy, 180);
        defender->pos_enemy.x += 105;
        defender->pos_enemy.y += 20;
        defender->count_path = 4;
    }
    if (defender->count_path == 4)
        defender->pos_enemy.y -= 10;
    if (defender->count_path == 4 && defender->pos_enemy.y == 515) {
        sfSprite_setRotation(defender->enemy, 90);
        defender->pos_enemy.y -= 80;
        defender->count_path = 5;
    } if (defender->count_path == 5)
        defender->pos_enemy.x -= 10;
    if (defender->count_path == 5 && defender->pos_enemy.x == 1045) {
        sfSprite_setRotation(defender->enemy, 0);
        defender->pos_enemy.x -= 105;
        defender->count_path = 6; }
}

void call_path1(defender_t *defender)
{
    if (defender->count_path == 0 && defender->cnt_enemy == 0) {
        defender->enemy_life = 3 + defender->tacapte;
        defender->cnt_enemy = 1;
    }
    if (defender->count_path == 0)
        defender->pos_enemy.y += 10;
    if (defender->count_path == 0 && defender->pos_enemy.y == 70) {
        sfSprite_setRotation(defender->enemy, 90);
        defender->pos_enemy.x += 60;
        defender->count_path = 1;
    }
    if (defender->count_path == 1)
        defender->pos_enemy.x -= 10;
    if (defender->count_path == 1 && defender->pos_enemy.x == 370) {
        sfSprite_setRotation(defender->enemy, 0);
        defender->pos_enemy.x -= 80;
        defender->count_path = 2;
    } if (defender->count_path == 2)
        defender->pos_enemy.y += 10;
    call_path9(defender);
}

void enemy_path(defender_t *defender)
{
    call_path1(defender);
    call_path2(defender);
    call_path3(defender);
    call_path4(defender);
    call_path5(defender);
    call_path6(defender);
    call_path7(defender);
    call_path8(defender);
}