/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"

void call_shot28(defender_t *defender)
{
    if (defender->pos_shot7.y != defender->pos27 &&
    defender->pos_ms.y >= defender->pos_shot7.y) {
        if (defender->count27 == 0) {
            defender->e1 = defender->dy15 / 100;
            defender->stop_shoty7 += defender->e1;
            defender->count27 = 1;
        }
        defender->pos_shot7.y += defender->e1;
    }
    if (defender->pos_shot7.y != defender->pos28 &&
    defender->pos_ms.y <= defender->pos_shot7.y) {
        if (defender->count28 == 0) {
            defender->f1 = defender->dy15 / 100;
            defender->stop_shoty7 += defender->f1;
            defender->count28 = 1;
        }
        defender->pos_shot7.y += defender->f1;
    }
}

void call_shot27(defender_t *defender)
{
    if (defender->pos_shot7.x != defender->pos26 &&
    defender->pos_ms.x <= defender->pos_shot7.x) {
        if (defender->count25 == 0) {
            defender->c1 = defender->dx15 / 100;
            defender->stop_shotx7 += defender->c1;
            defender->count25 = 1;
        }
        defender->pos_shot7.x += defender->c1;
    }
    if (defender->pos_shot7.x != defender->pos25 &&
    defender->pos_ms.x >= defender->pos_shot7.x) {
        if (defender->count26 == 0) {
            defender->d1 = defender->dx15 / 100;
            defender->stop_shotx7 += defender->d1;
            defender->count26 = 1;
        }
        defender->pos_shot7.x += defender->d1;
    }
}

void rst_sh7(defender_t *defender)
{
    if ((defender->pos_shot7.x >= 1920 && defender->trigger7 == 1) ||
    (defender->pos_shot7.x <= 0 && defender->trigger7 == 1) ||
    (defender->pos_shot7.y >= 1080 && defender->trigger7 == 1) ||
    (defender->pos_shot7.y <= 0 && defender->trigger7 == 1)) {
        defender->pos_shot7.x = 1130;
        defender->pos_shot7.y = 850;
        defender->count25 = 0;
        defender->count26 = 0;
        defender->count27 = 0;
        defender->count28 = 0;
        if (defender->count_zik7 == 0)
            defender->count_zik7 = 1;
        defender->trigger7 = 2;
        defender->stop_shotx7 = 0;
        defender->stop_shoty7 = 0;
    }
}

void call_shot26(defender_t *defender)
{
    if (defender->pos_shot7.y != defender->pos27 &&
    defender->pos_ms.y >= defender->pos_shot7.y) {
        if (defender->count27 == 0) {
            defender->e1 = defender->dy15 / 100;
            defender->stop_shoty7 += defender->e1;
            defender->count27 = 1;
        }
        defender->pos_shot7.y += defender->e1;
    }
    if (defender->pos_shot7.y != defender->pos28 &&
    defender->pos_ms.y <= defender->pos_shot7.y) {
        if (defender->count28 == 0) {
            defender->f1 = defender->dy15 / 100;
            defender->stop_shoty7 += defender->f1;
            defender->count28 = 1;
        }
        defender->pos_shot7.y += defender->f1;
    }
}

void call_shot25(defender_t *defender)
{
    if (defender->pos_shot7.x != defender->pos25 &&
    defender->pos_ms.x <= defender->pos_shot7.x) {
        if (defender->count25 == 0) {
            defender->c1 = defender->dx15 / 100;
            defender->stop_shotx7 += defender->c1;
            defender->count25 = 1;
        }
        defender->pos_shot7.x += defender->c1;
    }
    if (defender->pos_shot7.x != defender->pos26 &&
    defender->pos_ms.x >= defender->pos_shot7.x) {
        if (defender->count26 == 0) {
            defender->d1 = defender->dx15 / 100;
            defender->stop_shotx7 += defender->d1;
            defender->count26 = 1;
        }
        defender->pos_shot7.x += defender->d1;
    }
}