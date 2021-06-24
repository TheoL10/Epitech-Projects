/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void call_shdir4(defender_t *defender)
{
    if (defender->trigger2 == 2) {
        const float pi2 = 3.14159265;
        defender->di2 = defender->pos_ms.x - defender->pos_shot2.x;
        defender->diy2 = defender->pos_ms.y - defender->pos_shot2.y;
        float rotation2 = (atan2(defender->diy2, defender->di2)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot2, defender->origin_shot2);
        sfSprite_setRotation(defender->shot2, rotation2 + 180);
        defender->dx5 = defender->di2 * 5;
        defender->dy5 = defender->diy2 * 5;
        defender->dx6 = defender->di2;
        defender->dy6 = defender->diy2;
        defender->pos5 = (defender->pos_shot2.x - defender->dx6);
        defender->pos6 = (defender->pos_shot2.x + defender->dx6);
        defender->pos7 = (defender->pos_shot2.y + defender->dy6);
        defender->pos8 = (defender->pos_shot2.y - defender->dy6);
        defender->trigger2 = 3;
    }
}

void call_shdir3(defender_t *defender)
{
    if (defender->trigger2 == 0) {
        const float pi2 = 3.14159265;
        defender->di2 = defender->pos_ms.x - defender->pos_shot2.x;
        defender->diy2 = defender->pos_ms.y - defender->pos_shot2.y;
        float rotation2 = (atan2(defender->diy2, defender->di2)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot2, defender->origin_shot2);
        sfSprite_setRotation(defender->shot2, rotation2 + 180);
        defender->dx5 = defender->di2 * 40;
        defender->dy5 = defender->diy2 * 40;
        defender->dx6 = defender->di2;
        defender->dy6 = defender->diy2;
        defender->pos5 = (defender->pos_shot2.x - defender->dx6);
        defender->pos6 = (defender->pos_shot2.x + defender->dx6);
        defender->pos7 = (defender->pos_shot2.y + defender->dy6);
        defender->pos8 = (defender->pos_shot2.y - defender->dy6);
        defender->trigger2 = 1;
    }
}

void call_shdir2(defender_t *defender)
{
    if (defender->trigger == 2) {
        const float pi2 = 3.14159265;
        defender->dx2 = defender->pos_ms.x - defender->pos_shot.x;
        defender->dy2 = defender->pos_ms.y - defender->pos_shot.y;
        float rotation2 = (atan2(defender->dy2, defender->dx2)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot, defender->origin_shot);
        sfSprite_setRotation(defender->shot, rotation2 + 180);
        defender->dx3 = defender->dx2 * 5;
        defender->dy3 = defender->dy2 * 5;
        defender->dx4 = defender->dx2;
        defender->dy4 = defender->dy2;
        defender->pos1 = (defender->pos_shot.x - defender->dx4);
        defender->pos2 = (defender->pos_shot.x + defender->dx4);
        defender->pos3 = (defender->pos_shot.y + defender->dy4);
        defender->pos4 = (defender->pos_shot.y - defender->dy4);
        defender->trigger = 3;
    }
}

void call_shdir1(defender_t *defender)
{
    if (defender->trigger == 0) {
        const float pi2 = 3.14159265;
        defender->dx2 = defender->pos_ms.x - defender->pos_shot.x;
        defender->dy2 = defender->pos_ms.y - defender->pos_shot.y;
        float rotation2 = (atan2(defender->dy2, defender->dx2)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot, defender->origin_shot);
        sfSprite_setRotation(defender->shot, rotation2 + 180);
        defender->dx3 = defender->dx2 * 40;
        defender->dy3 = defender->dy2 * 40;
        defender->dx4 = defender->dx2;
        defender->dy4 = defender->dy2;
        defender->pos1 = (defender->pos_shot.x - defender->dx4);
        defender->pos2 = (defender->pos_shot.x + defender->dx4);
        defender->pos3 = (defender->pos_shot.y + defender->dy4);
        defender->pos4 = (defender->pos_shot.y - defender->dy4);
        if (defender->count_zik1 == 0)
            defender->count_zik1 = 1;
        defender->trigger = 1;
    }
}