/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"

void call_shot12(defender_t *defender)
{
    if (defender->pos_shot3.y != defender->pos11 &&
    defender->pos_ms.y >= defender->pos_shot3.y) {
        if (defender->count11 == 0) {
            defender->o = defender->dy7 / 100;
            defender->stop_shoty3 += defender->o;
            defender->count11 = 1;
        }
        defender->pos_shot3.y += defender->o;
    }
    if (defender->pos_shot3.y != defender->pos12 &&
    defender->pos_ms.y <= defender->pos_shot3.y) {
        if (defender->count12 == 0) {
            defender->p = defender->dy7 / 100;
            defender->stop_shoty3 += defender->p;
            defender->count12 = 1;
        }
        defender->pos_shot3.y += defender->p;
    }
}

void call_shot11(defender_t *defender)
{
    if (defender->pos_shot3.x != defender->pos9 &&
    defender->pos_ms.x <= defender->pos_shot3.x) {
        if (defender->count9 == 0) {
            defender->m = defender->dx7 / 100;
            defender->stop_shotx3 += defender->m;
            defender->count9 = 1;
        }
        defender->pos_shot3.x += defender->m;
    }
    if (defender->pos_shot3.x != defender->pos10 &&
    defender->pos_ms.x >= defender->pos_shot3.x) {
        if (defender->count10 == 0) {
            defender->n = defender->dx7 / 100;
            defender->stop_shotx3 += defender->n;
            defender->count10 = 1;
        }
        defender->pos_shot3.x += defender->n;
    }
}

void rst_sh3(defender_t *defender)
{
    if ((defender->pos_shot3.x >= 1920 && defender->trigger3 == 1) ||
    (defender->pos_shot3.x <= 0 && defender->trigger3 == 1) ||
    (defender->pos_shot3.y >= 1080 && defender->trigger3 == 1) ||
    (defender->pos_shot3.y <= 0 && defender->trigger3 == 1)) {
        defender->pos_shot3.x = 805;
        defender->pos_shot3.y = 650;
        defender->count9 = 0;
        defender->count10 = 0;
        defender->count11 = 0;
        defender->count12 = 0;
        if (defender->count_zik3 == 0)
            defender->count_zik3 = 1;
        defender->trigger3 = 2;
        defender->stop_shotx3 = 0;
        defender->stop_shoty3 = 0;
    }
}

void call_shot10(defender_t *defender)
{
    if (defender->pos_shot3.y != defender->pos11 &&
    defender->pos_ms.y >= defender->pos_shot3.y) {
        if (defender->count11 == 0) {
            defender->o = defender->dy7 / 100;
            defender->stop_shoty3 += defender->o;
            defender->count11 = 1;
        }
        defender->pos_shot3.y += defender->o;
    }
    if (defender->pos_shot3.y != defender->pos12 &&
    defender->pos_ms.y <= defender->pos_shot3.y) {
        if (defender->count12 == 0) {
            defender->p = defender->dy7 / 100;
            defender->stop_shoty3 += defender->p;
            defender->count12 = 1;
        }
        defender->pos_shot3.y += defender->p;
    }
}

void call_shot9(defender_t *defender)
{
    if (defender->pos_shot3.x != defender->pos9 &&
    defender->pos_ms.x <= defender->pos_shot3.x) {
        if (defender->count9 == 0) {
            defender->m = defender->dx7 / 100;
            defender->stop_shotx3 += defender->m;
            defender->count9 = 1;
        }
        defender->pos_shot3.x += defender->m;
    }
    if (defender->pos_shot3.x != defender->pos10 &&
    defender->pos_ms.x >= defender->pos_shot3.x) {
        if (defender->count10 == 0) {
            defender->n = defender->dx7 / 100;
            defender->stop_shotx3 += defender->n;
            defender->count10 = 1;
        }
        defender->pos_shot3.x += defender->n;
    }
}