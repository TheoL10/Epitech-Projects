/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void call_shdir14(defender_t *defender)
{
    if (defender->trigger7 == 2) {
        const float pi2 = 3.14159265;
        defender->di7 = defender->pos_ms.x - defender->pos_shot7.x;
        defender->diy7 = defender->pos_ms.y - defender->pos_shot7.y;
        float rotation2 = (atan2(defender->diy7, defender->di7)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot7, defender->origin_shot7);
        sfSprite_setRotation(defender->shot7, rotation2 + 180);
        defender->dx15 = defender->di7 * 5;
        defender->dy15 = defender->diy7 * 5;
        defender->dx16 = defender->di7;
        defender->dy16 = defender->diy7;
        defender->pos25 = (defender->pos_shot7.x - defender->dx16);
        defender->pos26 = (defender->pos_shot7.x + defender->dx16);
        defender->pos27 = (defender->pos_shot7.y + defender->dy16);
        defender->pos28 = (defender->pos_shot7.y - defender->dy16);
        defender->trigger7 = 3;
    }
}

void call_shdir13(defender_t *defender)
{
    if (defender->trigger7 == 0) {
        const float pi2 = 3.14159265;
        defender->di7 = defender->pos_ms.x - defender->pos_shot7.x;
        defender->diy7 = defender->pos_ms.y - defender->pos_shot7.y;
        float rotation2 = (atan2(defender->diy7, defender->di7)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot7, defender->origin_shot7);
        sfSprite_setRotation(defender->shot7, rotation2 + 180);
        defender->dx15 = defender->di7 * 40;
        defender->dy15 = defender->diy7 * 40;
        defender->dx16 = defender->di7;
        defender->dy16 = defender->diy7;
        defender->pos25 = (defender->pos_shot7.x - defender->dx16);
        defender->pos26 = (defender->pos_shot7.x + defender->dx16);
        defender->pos27 = (defender->pos_shot7.y + defender->dy16);
        defender->pos28 = (defender->pos_shot7.y - defender->dy16);
        defender->trigger7 = 1;
    }
}

void enemy_shot8(defender_t *defender)
{
    if ((defender->pos_shot5.x >= 1920 && defender->trigger5 == 3) ||
    (defender->pos_shot5.x <= 0 &&
    defender->trigger5 == 3) || (defender->pos_shot5.y >= 1080 &&
    defender->trigger5 == 3) || (defender->pos_shot5.y <= 0 &&
    defender->trigger5 == 3)) {
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

void enemy_shot9(defender_t *defender)
{
    if ((defender->pos_shot4.x >= 1920 && defender->trigger4 == 3) ||
    (defender->pos_shot4.x <= 0 &&
    defender->trigger4 == 3) || (defender->pos_shot4.y >= 1080 &&
    defender->trigger4 == 3) || (defender->pos_shot4.y <= 0 &&
    defender->trigger4 == 3)) { defender->pos_shot4.x = 485;
        defender->pos_shot4.y = 800;
        defender->count13 = 0;
        defender->count14 = 0;
        defender->count15 = 0;
        defender->count16 = 0;
        if (defender->count_zik4 == 0)
            defender->count_zik4 = 1;
        defender->trigger4 = 2;
        defender->stop_shotx4 = 0;
        defender->stop_shoty4 = 0; }
}

void enemy_shot13(defender_t *defender)
{
    if ((defender->pos_shot.x >= 1920 && defender->trigger == 3) ||
    (defender->pos_shot.x <= 0 && defender->trigger == 3) ||
    (defender->pos_shot.y >= 1080 && defender->trigger == 3) ||
    (defender->pos_shot.y <= 0 && defender->trigger == 3)) {
        defender->pos_shot.x = 485;
        defender->pos_shot.y = 270;
        defender->count = 0;
        defender->count2 = 0;
        defender->count3 = 0;
        defender->count4 = 0;
        defender->stop_shotx = 0;
        defender->stop_shoty = 0;
        if (defender->count_zik1 == 0)
            defender->count_zik1 = 1;
        defender->trigger = 2; }
}