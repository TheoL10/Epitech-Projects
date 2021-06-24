/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void call_shdir8(defender_t *defender)
{
    if (defender->trigger4 == 2) {
        const float pi2 = 3.14159265;
        defender->di4 = defender->pos_ms.x - defender->pos_shot4.x;
        defender->diy4 = defender->pos_ms.y - defender->pos_shot4.y;
        float rotation2 = (atan2(defender->diy4, defender->di4)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot4, defender->origin_shot4);
        sfSprite_setRotation(defender->shot4, rotation2 + 180);
        defender->dx9 = defender->di4 * 5;
        defender->dy9 = defender->diy4 * 5;
        defender->dx10 = defender->di4;
        defender->dy10 = defender->diy4;
        defender->pos13 = (defender->pos_shot4.x - defender->dx10);
        defender->pos14 = (defender->pos_shot3.x + defender->dx10);
        defender->pos15 = (defender->pos_shot3.y + defender->dy10);
        defender->pos16 = (defender->pos_shot3.y - defender->dy10);
        defender->trigger4 = 3;
    }
}

void call_shdir7(defender_t *defender)
{
    if (defender->trigger4 == 0) {
        const float pi2 = 3.14159265;
        defender->di4 = defender->pos_ms.x - defender->pos_shot4.x;
        defender->diy4 = defender->pos_ms.y - defender->pos_shot4.y;
        float rotation2 = (atan2(defender->diy4, defender->di4)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot4, defender->origin_shot3);
        sfSprite_setRotation(defender->shot4, rotation2 + 180);
        defender->dx9 = defender->di4 * 40;
        defender->dy9 = defender->diy4 * 40;
        defender->dx10 = defender->di4;
        defender->dy10 = defender->diy4;
        defender->pos13 = (defender->pos_shot4.x - defender->dx10);
        defender->pos14 = (defender->pos_shot4.x + defender->dx10);
        defender->pos15 = (defender->pos_shot4.y + defender->dy10);
        defender->pos16 = (defender->pos_shot4.y - defender->dy10);
        defender->trigger4 = 1;
    }
}

void call_shdir6(defender_t *defender)
{
    if (defender->trigger3 == 2) {
        const float pi2 = 3.14159265;
        defender->di3 = defender->pos_ms.x - defender->pos_shot3.x;
        defender->diy3 = defender->pos_ms.y - defender->pos_shot3.y;
        float rotation2 = (atan2(defender->diy3, defender->di3)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot3, defender->origin_shot3);
        sfSprite_setRotation(defender->shot3, rotation2 + 180);
        defender->dx7 = defender->di3 * 5;
        defender->dy7 = defender->diy3 * 5;
        defender->dx8 = defender->di3;
        defender->dy8 = defender->diy3;
        defender->pos9 = (defender->pos_shot3.x - defender->dx8);
        defender->pos10 = (defender->pos_shot3.x + defender->dx8);
        defender->pos11 = (defender->pos_shot3.y + defender->dy8);
        defender->pos12 = (defender->pos_shot3.y - defender->dy8);
        defender->trigger3 = 3;
    }
}

void call_shdir5(defender_t *defender)
{
    if (defender->trigger3 == 0) {
        const float pi2 = 3.14159265;
        defender->di3 = defender->pos_ms.x - defender->pos_shot3.x;
        defender->diy3 = defender->pos_ms.y - defender->pos_shot3.y;
        float rotation2 = (atan2(defender->diy3, defender->di3)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot3, defender->origin_shot3);
        sfSprite_setRotation(defender->shot3, rotation2 + 180);
        defender->dx7 = defender->di3 * 40;
        defender->dy7 = defender->diy3 * 40;
        defender->dx8 = defender->di3;
        defender->dy8 = defender->diy3;
        defender->pos9 = (defender->pos_shot3.x - defender->dx8);
        defender->pos10 = (defender->pos_shot3.x + defender->dx8);
        defender->pos11 = (defender->pos_shot3.y + defender->dy8);
        defender->pos12 = (defender->pos_shot3.y - defender->dy8);
        defender->trigger3 = 1;
    }
}