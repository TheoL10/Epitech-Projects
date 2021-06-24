/*
** EPITECH PROJECT, 2021
** shot_dir5
** File description:
** shot_dir5
*/

#include "include/my.h"
#include "include/struct.h"

void enemy_shot11(defender_t *defender)
{
    if ((defender->pos_shot3.x >= 1920 && defender->trigger3 == 3) ||
    (defender->pos_shot3.x <= 0 &&
    defender->trigger3 == 3) || (defender->pos_shot3.y >= 1080 &&
    defender->trigger3 == 3) || (defender->pos_shot3.y <= 0 &&
    defender->trigger3 == 3)) { defender->pos_shot3.x = 805;
        defender->pos_shot3.y = 650;
        defender->count9 = 0;
        defender->count10 = 0;
        defender->count11 = 0;
        defender->count12 = 0;
        if (defender->count_zik3 == 0)
            defender->count_zik3 = 1;
        defender->trigger3 = 2;
        defender->stop_shotx3 = 0;
        defender->stop_shoty3 = 0; }
}

void enemy_shot12(defender_t *defender)
{
    if ((defender->pos_shot2.x >= 1920 && defender->trigger2 == 3) ||
    (defender->pos_shot2.x <= 0 &&
    defender->trigger2 == 3) || (defender->pos_shot2.y >= 1080 &&
    defender->trigger2 == 3) || (defender->pos_shot2.y <= 0 &&
    defender->trigger2 == 3)) { defender->pos_shot2.x = 815;
        defender->pos_shot2.y = 420;
        defender->count5 = 0;
        defender->count6 = 0;
        defender->count7 = 0;
        defender->count8 = 0;
        if (defender->count_zik2 == 0)
            defender->count_zik2 = 1;
        defender->trigger2 = 2;
        defender->stop_shotx2 = 0;
        defender->stop_shoty2 = 0; }
}

void enemy_shot14(defender_t *defender)
{
    if ((defender->pos_shot7.x >= 1920 && defender->trigger7 == 3) ||
    (defender->pos_shot7.x <= 0 &&
    defender->trigger7 == 3) || (defender->pos_shot7.y >= 1080 &&
    defender->trigger7 == 3) || (defender->pos_shot7.y <= 0 &&
    defender->trigger7 == 3)) { defender->pos_shot7.x = 1130;
        defender->pos_shot7.y = 850;
        defender->count25 = 0;
        defender->count26 = 0;
        defender->count27 = 0;
        defender->count28 = 0;
        if (defender->count_zik7 == 0)
            defender->count_zik7 = 1;
        defender->trigger7 = 2;
        defender->stop_shotx7 = 0;
        defender->stop_shoty7 = 0; }
}

void enemy_shot15(defender_t *defender)
{
    if ((defender->pos_shot6.x >= 1920 && defender->trigger6 == 3) ||
    (defender->pos_shot6.x <= 0 &&
    defender->trigger6 == 3) || (defender->pos_shot6.y >= 1080 &&
    defender->trigger6 == 3) || (defender->pos_shot6.y <= 0 &&
    defender->trigger6 == 3)) { defender->pos_shot6.x = 1465;
        defender->pos_shot6.y = 450;
        defender->count21 = 0;
        defender->count22 = 0;
        defender->count23 = 0;
        defender->count24 = 0;
        if (defender->count_zik6 == 0)
            defender->count_zik6 = 1;
        defender->trigger6 = 2;
        defender->stop_shotx6 = 0;
        defender->stop_shoty6 = 0; }
}