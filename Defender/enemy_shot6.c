/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"

void call_shot24(defender_t *defender)
{
    if (defender->pos_shot6.y != defender->pos23 &&
    defender->pos_ms.y >= defender->pos_shot6.y) {
        if (defender->count23 == 0) {
            defender->a1 = defender->dy13 / 100;
            defender->stop_shoty6 += defender->a1;
            defender->count23 = 1;
        }
        defender->pos_shot6.y += defender->a1;
    }
    if (defender->pos_shot6.y != defender->pos24 &&
    defender->pos_ms.y <= defender->pos_shot6.y) {
        if (defender->count24 == 0) {
            defender->b1 = defender->dy13 / 100;
            defender->stop_shoty6 += defender->b1;
            defender->count24 = 1;
        }
        defender->pos_shot6.y += defender->b1;
    }
}

void call_shot23(defender_t *defender)
{
    if (defender->pos_shot6.x != defender->pos22 &&
    defender->pos_ms.x <= defender->pos_shot6.x) {
        if (defender->count21 == 0) {
            defender->y = defender->dx13 / 100;
            defender->stop_shotx6 += defender->y;
            defender->count21 = 1;
        }
        defender->pos_shot6.x += defender->y;
    }
    if (defender->pos_shot6.x != defender->pos21 &&
    defender->pos_ms.x >= defender->pos_shot6.x) {
        if (defender->count22 == 0) {
            defender->z = defender->dx13 / 100;
            defender->stop_shotx6 += defender->z;
            defender->count22 = 1;
        }
        defender->pos_shot6.x += defender->z;
    }
}

void rst_sh6(defender_t *defender)
{
    if ((defender->pos_shot6.x >= 1920 && defender->trigger6 == 1) ||
    (defender->pos_shot6.x <= 0 && defender->trigger6 == 1) ||
    (defender->pos_shot6.y >= 1080 && defender->trigger6 == 1) ||
    (defender->pos_shot6.y <= 0 && defender->trigger6 == 1)) {
        defender->pos_shot6.x = 1465;
        defender->pos_shot6.y = 450;
        defender->count21 = 0;
        defender->count22 = 0;
        defender->count23 = 0;
        defender->count24 = 0;
        if (defender->count_zik6 == 0)
            defender->count_zik6 = 1;
        defender->trigger6 = 2;
        defender->stop_shotx6 = 0;
        defender->stop_shoty6 = 0;
    }
}

void call_shot22(defender_t *defender)
{
    if (defender->pos_shot6.y != defender->pos23 &&
    defender->pos_ms.y >= defender->pos_shot6.y) {
        if (defender->count23 == 0) {
            defender->a1 = defender->dy13 / 100;
            defender->stop_shoty6 += defender->a1;
            defender->count23 = 1;
        }
        defender->pos_shot6.y += defender->a1;
    }
    if (defender->pos_shot6.y != defender->pos24 &&
    defender->pos_ms.y <= defender->pos_shot6.y) {
        if (defender->count24 == 0) {
            defender->b1 = defender->dy13 / 100;
            defender->stop_shoty6 += defender->b1;
            defender->count24 = 1;
        }
        defender->pos_shot6.y += defender->b1;
    }
}

void call_shot21(defender_t *defender)
{
    if (defender->pos_shot6.x != defender->pos21 &&
    defender->pos_ms.x <= defender->pos_shot6.x) {
        if (defender->count21 == 0) {
            defender->y = defender->dx13 / 100;
            defender->stop_shotx6 += defender->y;
            defender->count21 = 1;
        }
        defender->pos_shot6.x += defender->y;
    }
    if (defender->pos_shot6.x != defender->pos22 &&
    defender->pos_ms.x >= defender->pos_shot6.x) {
        if (defender->count22 == 0) {
            defender->z = defender->dx13 / 100;
            defender->stop_shotx6 += defender->z;
            defender->count22 = 1;
        }
        defender->pos_shot6.x += defender->z;
    }
}