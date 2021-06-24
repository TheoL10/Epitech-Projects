/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"

void call_shot16(defender_t *defender)
{
    if (defender->pos_shot4.y != defender->pos15 &&
    defender->pos_ms.y >= defender->pos_shot4.y) {
        if (defender->count15 == 0) {
            defender->s = defender->dy9 / 100;
            defender->stop_shoty4 += defender->s;
            defender->count15 = 1;
        }
        defender->pos_shot4.y += defender->s;
    }
    if (defender->pos_shot4.y != defender->pos16 &&
    defender->pos_ms.y <= defender->pos_shot4.y) {
        if (defender->count16 == 0) {
            defender->t = defender->dy9 / 100;
            defender->stop_shoty4 += defender->t;
            defender->count16 = 1;
        }
        defender->pos_shot4.y += defender->t;
    }
}

void call_shot15(defender_t *defender)
{
    if (defender->pos_shot4.x != defender->pos13 &&
    defender->pos_ms.x <= defender->pos_shot4.x) {
        if (defender->count13 == 0) {
            defender->q = defender->dx9 / 100;
            defender->stop_shotx4 += defender->q;
            defender->count13 = 1;
        }
        defender->pos_shot4.x += defender->q;
    }
    if (defender->pos_shot4.x != defender->pos14 &&
    defender->pos_ms.x >= defender->pos_shot4.x) {
        if (defender->count14 == 0) {
            defender->r = defender->dx9 / 100;
            defender->stop_shotx4 += defender->r;
            defender->count14 = 1;
        }
        defender->pos_shot4.x += defender->r;
    }
}

void rst_sh4(defender_t *defender)
{
    if ((defender->pos_shot4.x >= 1920 && defender->trigger4 == 1) ||
    (defender->pos_shot4.x <= 0 && defender->trigger4 == 1) ||
    (defender->pos_shot4.y >= 1080 && defender->trigger4 == 1) ||
    (defender->pos_shot4.y <= 0 && defender->trigger4 == 1)) {
        defender->pos_shot4.x = 485;
        defender->pos_shot4.y = 800;
        defender->count13 = 0;
        defender->count14 = 0;
        defender->count15 = 0;
        defender->count16 = 0;
        if (defender->count_zik4 == 0)
            defender->count_zik4 = 1;
        defender->trigger4 = 2;
        defender->stop_shotx4 = 0;
        defender->stop_shoty4 = 0;
    }
}

void call_shot14(defender_t *defender)
{
    if (defender->pos_shot4.y != defender->pos15 &&
    defender->pos_ms.y >= defender->pos_shot4.y) {
        if (defender->count15 == 0) {
            defender->s = defender->dy9 / 100;
            defender->stop_shoty4 += defender->s;
            defender->count15 = 1;
        }
        defender->pos_shot4.y += defender->s;
    }
    if (defender->pos_shot4.y != defender->pos16 &&
    defender->pos_ms.y <= defender->pos_shot4.y) {
        if (defender->count16 == 0) {
            defender->t = defender->dy9 / 100;
            defender->stop_shoty4 += defender->t;
            defender->count16 = 1;
        }
        defender->pos_shot4.y += defender->t;
    }
}

void call_shot13(defender_t *defender)
{
    if (defender->pos_shot4.x != defender->pos13 &&
    defender->pos_ms.x <= defender->pos_shot4.x) {
        if (defender->count13 == 0) {
            defender->q = defender->dx9 / 100;
            defender->stop_shotx4 += defender->m;
            defender->count13 = 1;
        }
        defender->pos_shot4.x += defender->m;
    }
    if (defender->pos_shot4.x != defender->pos14 &&
    defender->pos_ms.x >= defender->pos_shot4.x) {
        if (defender->count14 == 0) {
            defender->r = defender->dx9 / 100;
            defender->stop_shotx4 += defender->r;
            defender->count14 = 1;
        }
        defender->pos_shot4.x += defender->r;
    }
}