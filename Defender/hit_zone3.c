/*
** EPITECH PROJECT, 2021
** hit_zone3
** File description:
** hit_zone3
*/

#include "include/my.h"
#include "include/struct.h"

void check_hit10(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot3.x = 805;
        defender->pos_shot3.y = 650;
        defender->zin2 = 0;
        defender->enemy_life2 -= 1;
        defender->count9 = 0;
        defender->count10 = 0;
        defender->count11 = 0;
        defender->count12 = 0;
        defender->stop_shotx3 = 0;
        defender->stop_shoty3 = 0;
        defender->trigger3 = 2;
    }
}

void check_hit9(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot2.x = 815;
        defender->pos_shot2.y = 420;
        defender->zin2 = 0;
        defender->enemy_life2 -= 1;
        defender->count5 = 0;
        defender->count6 = 0;
        defender->count7 = 0;
        defender->count8 = 0;
        defender->stop_shotx2 = 0;
        defender->stop_shoty2 = 0;
        defender->trigger2 = 2;
    }
}

void check_hit8(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot.x = 485;
        defender->pos_shot.y = 270;
        defender->zin2 = 0;
        defender->enemy_life2 -= 1;
        defender->count = 0;
        defender->count2 = 0;
        defender->count3 = 0;
        defender->count4 = 0;
        defender->stop_shotx = 0;
        defender->stop_shoty = 0;
        defender->trigger = 2;
    }
}

void check_hit7(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot7.x = 1130;
        defender->pos_shot7.y = 850;
        defender->zin = 0;
        defender->enemy_life -= 1;
        defender->count25 = 0;
        defender->count26 = 0;
        defender->count27 = 0;
        defender->count28 = 0;
        defender->stop_shotx7 = 0;
        defender->stop_shoty7 = 0;
        defender->trigger7 = 2;
    }
}

void check_hit6(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot6.x = 1465;
        defender->pos_shot6.y = 600;
        defender->zin = 0;
        defender->enemy_life -= 1;
        defender->count21 = 0;
        defender->count22 = 0;
        defender->count23 = 0;
        defender->count24 = 0;
        defender->stop_shotx6 = 0;
        defender->stop_shoty6 = 0;
        defender->trigger6 = 2;
    }
}