/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"

void call_shot8(defender_t *defender)
{
    if (defender->pos_shot2.y != defender->pos7 &&
    defender->pos_ms.y >= defender->pos_shot2.y) {
        if (defender->count7 == 0) {
            defender->k = defender->dy5 / 100;
            defender->stop_shoty2 += defender->k;
            defender->count7 = 1;
        }
        defender->pos_shot2.y += defender->k;
    }
    if (defender->pos_shot2.y != defender->pos8 &&
    defender->pos_ms.y <= defender->pos_shot2.y) {
        if (defender->count8 == 0) {
            defender->l = defender->dy5 / 100;
            defender->stop_shoty2 += defender->l;
            defender->count8 = 1;
        }
        defender->pos_shot2.y += defender->l;
    }
}

void call_shot7(defender_t *defender)
{
    if (defender->pos_shot2.x != defender->pos5 &&
    defender->pos_ms.x <= defender->pos_shot2.x) {
        if (defender->count5 == 0) {
            defender->i = defender->dx5 / 100;
            defender->stop_shotx2 += defender->i;
            defender->count5 = 1;
        }
        defender->pos_shot2.x += defender->i;
    }
    if (defender->pos_shot2.x != defender->pos6 &&
    defender->pos_ms.x >= defender->pos_shot2.x) {
        if (defender->count6 == 0) {
            defender->j = defender->dx5 / 100;
            defender->stop_shotx2 += defender->j;
            defender->count6 = 1;
        }
        defender->pos_shot2.x += defender->j;
    }
}

void rst_sh2(defender_t *defender)
{
    if ((defender->pos_shot2.x >= 1920 && defender->trigger2 == 1) ||
    (defender->pos_shot2.x <= 0 && defender->trigger2 == 1) ||
    (defender->pos_shot2.y >= 1080 && defender->trigger2 == 1) ||
    (defender->pos_shot2.y <= 0 && defender->trigger2 == 1)) {
        defender->pos_shot2.x = 815;
        defender->pos_shot2.y = 420;
        defender->count5 = 0;
        defender->count6 = 0;
        defender->count7 = 0;
        defender->count8 = 0;
        if (defender->count_zik2 == 0)
            defender->count_zik2 = 1;
        defender->trigger2 = 2;
        defender->stop_shotx2 = 0;
        defender->stop_shoty2 = 0;
    }
}

void call_shot6(defender_t *defender)
{
    if (defender->pos_shot2.y != defender->pos7 &&
    defender->pos_ms.y >= defender->pos_shot2.y) {
        if (defender->count7 == 0) {
            defender->k = defender->dy5 / 100;
            defender->stop_shoty2 += defender->k;
            defender->count7 = 1;
        }
        defender->pos_shot2.y += defender->k;
    }
    if (defender->pos_shot2.y != defender->pos8 &&
    defender->pos_ms.y <= defender->pos_shot2.y) {
        if (defender->count8 == 0) {
            defender->l = defender->dy5 / 100;
            defender->stop_shoty2 += defender->l;
            defender->count8 = 1;
        }
        defender->pos_shot2.y += defender->l;
    }
}

void call_shot5(defender_t *defender)
{
    if (defender->pos_shot2.x != defender->pos5 &&
    defender->pos_ms.x <= defender->pos_shot2.x) {
        if (defender->count5 == 0) {
            defender->i = defender->dx5 / 100;
            defender->stop_shotx2 += defender->i;
            defender->count5 = 1;
        }
        defender->pos_shot2.x += defender->i;
    }
    if (defender->pos_shot2.x != defender->pos6 &&
    defender->pos_ms.x >= defender->pos_shot2.x) {
        if (defender->count6 == 0) {
            defender->j = defender->dx5 / 100;
            defender->stop_shotx2 += defender->j;
            defender->count6 = 1;
        }
        defender->pos_shot2.x += defender->j;
    }
}