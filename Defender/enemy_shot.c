/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"

void call_sh4(defender_t *defender)
{
    if (defender->pos_shot.y != defender->pos3 &&
    defender->pos_ms.y >= defender->pos_shot.y) {
        if (defender->count3 == 0) {
            defender->g = defender->dy3 / 100;
            defender->stop_shoty += defender->g;
            defender->count3 = 1;
        }
        defender->pos_shot.y += defender->g;
    }
    if (defender->pos_shot.y != defender->pos4 &&
    defender->pos_ms.y <= defender->pos_shot.y) {
        if (defender->count4 == 0) {
            defender->h = defender->dy3 / 100;
            defender->stop_shoty += defender->h;
            defender->count4 = 1;
        }
        defender->pos_shot.y += defender->h;
    }
}

void call_sh3(defender_t *defender)
{
    if (defender->pos_shot.x != defender->pos1 &&
    defender->pos_ms.x <= defender->pos_shot.x) {
        if (defender->count == 0) {
            defender->e = defender->dx3 / 100;
            defender->stop_shotx += defender->e;
            defender->count = 1;
        }
        defender->pos_shot.x += defender->e;
    }
    if (defender->pos_shot.x != defender->pos2 &&
    defender->pos_ms.x >= defender->pos_shot.x) {
        if (defender->count2 == 0) {
            defender->f = defender->dx3 / 100;
            defender->stop_shotx += defender->f;
            defender->count2 = 1;
        }
        defender->pos_shot.x += defender->f;
    }
}

void rst_sh1(defender_t *defender)
{
    if ((defender->pos_shot.x >= 1920 && defender->trigger == 1) ||
    (defender->pos_shot.x <= 0 && defender->trigger == 1) ||
    (defender->pos_shot.y >= 1080 && defender->trigger == 1) ||
    (defender->pos_shot.y <= 0 && defender->trigger == 1)) {
        defender->pos_shot.x = 485;
        defender->pos_shot.y = 270;
        defender->count = 0;
        defender->count2 = 0;
        defender->count3 = 0;
        defender->count4 = 0;
        if (defender->count_zik1 == 0)
            defender->count_zik1 = 1;
        defender->trigger = 2;
        defender->stop_shotx = 0;
        defender->stop_shoty = 0;
    }
}

void call_sh2(defender_t *defender)
{
    if (defender->pos_shot.y != defender->pos3 &&
    defender->pos_ms.y >= defender->pos_shot.y) {
        if (defender->count3 == 0) {
            defender->g = defender->dy3 / 100;
            defender->stop_shoty += defender->g;
            defender->count3 = 1;
        }
        defender->pos_shot.y += defender->g;
    }
    if (defender->pos_shot.y != defender->pos4 &&
    defender->pos_ms.y <= defender->pos_shot.y) {
        if (defender->count4 == 0) {
            defender->h = defender->dy3 / 100;
            defender->stop_shoty += defender->h;
            defender->count4 = 1;
        }
        defender->pos_shot.y += defender->h;
    }
}

void call_sh1(defender_t *defender)
{
    if (defender->pos_shot.x != defender->pos1 &&
    defender->pos_ms.x <= defender->pos_shot.x) {
        if (defender->count == 0) {
            defender->e = defender->dx3 / 100;
            defender->stop_shotx += defender->e;
            defender->count = 1;
        }
        defender->pos_shot.x += defender->e;
    }
    if (defender->pos_shot.x != defender->pos2 &&
    defender->pos_ms.x >= defender->pos_shot.x) {
        if (defender->count2 == 0) {
            defender->f = defender->dx3 / 100;
            defender->stop_shotx += defender->f;
            defender->count2 = 1;
        }
        defender->pos_shot.x += defender->f;
    }
}