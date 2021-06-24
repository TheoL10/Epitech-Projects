/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"

void call_shot20(defender_t *defender)
{
    if (defender->pos_shot5.y != defender->pos19 &&
    defender->pos_ms.y >= defender->pos_shot5.y) {
        if (defender->count19 == 0) {
            defender->x = defender->dy11 / 100;
            defender->stop_shoty5 += defender->x;
            defender->count19 = 1;
        }
        defender->pos_shot5.y += defender->x;
    }
    if (defender->pos_shot5.y != defender->pos20 &&
    defender->pos_ms.y <= defender->pos_shot5.y) {
        if (defender->count20 == 0) {
            defender->y = defender->dy11 / 100;
            defender->stop_shoty5 += defender->y;
            defender->count20 = 1;
        }
        defender->pos_shot5.y += defender->y;
    }
}

void call_shot19(defender_t *defender)
{
    if (defender->pos_shot5.x != defender->pos18 &&
    defender->pos_ms.x <= defender->pos_shot5.x) {
        if (defender->count17 == 0) {
            defender->u = defender->dx11 / 100;
            defender->stop_shotx5 += defender->u;
            defender->count17 = 1;
        }
        defender->pos_shot5.x += defender->u;
    }
    if (defender->pos_shot5.x != defender->pos17 &&
    defender->pos_ms.x >= defender->pos_shot5.x) {
        if (defender->count18 == 0) {
            defender->v = defender->dx11 / 100;
            defender->stop_shotx5 += defender->v;
            defender->count18 = 1;
        }
        defender->pos_shot5.x += defender->v;
    }
}

void rst_sh5(defender_t *defender)
{
    if ((defender->pos_shot5.x >= 1920 && defender->trigger5 == 1) ||
    (defender->pos_shot5.x <= 0 && defender->trigger5 == 1) ||
    (defender->pos_shot5.y >= 1080 && defender->trigger5 == 1) ||
    (defender->pos_shot5.y <= 0 && defender->trigger5 == 1)) {
        defender->pos_shot5.x = 1130;
        defender->pos_shot5.y = 600;
        defender->count17 = 0;
        defender->count18 = 0;
        defender->count19 = 0;
        defender->count20 = 0;
        if (defender->count_zik5 == 0)
            defender->count_zik5 = 1;
        defender->trigger5 = 2;
        defender->stop_shotx5 = 0;
        defender->stop_shoty5 = 0;
    }
}

void call_shot18(defender_t *defender)
{
    if (defender->pos_shot5.y != defender->pos19 &&
    defender->pos_ms.y >= defender->pos_shot5.y) {
        if (defender->count19 == 0) {
            defender->x = defender->dy11 / 100;
            defender->stop_shoty5 += defender->x;
            defender->count19 = 1;
        }
        defender->pos_shot5.y += defender->x;
    }
    if (defender->pos_shot5.y != defender->pos20 &&
    defender->pos_ms.y <= defender->pos_shot5.y) {
        if (defender->count20 == 0) {
            defender->y = defender->dy11 / 100;
            defender->stop_shoty5 += defender->y;
            defender->count20 = 1;
        }
        defender->pos_shot5.y += defender->y;
    }
}

void call_shot17(defender_t *defender)
{
    if (defender->pos_shot5.x != defender->pos17 &&
    defender->pos_ms.x <= defender->pos_shot5.x) {
        if (defender->count17 == 0) {
            defender->u = defender->dx11 / 100;
            defender->stop_shotx5 += defender->u;
            defender->count17 = 1;
        }
        defender->pos_shot5.x += defender->u;
    }
    if (defender->pos_shot5.x != defender->pos18 &&
    defender->pos_ms.x >= defender->pos_shot5.x) {
        if (defender->count18 == 0) {
            defender->v = defender->dx11 / 100;
            defender->stop_shotx5 += defender->v;
            defender->count18 = 1;
        }
        defender->pos_shot5.x += defender->v;
    }
}