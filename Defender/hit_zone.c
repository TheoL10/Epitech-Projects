/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"

void check_hit14(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot7.x = 1130;
        defender->pos_shot7.y = 850;
        defender->zin2 = 0;
        defender->enemy_life2 -= 1;
        defender->count25 = 0;
        defender->count26 = 0;
        defender->count27 = 0;
        defender->count28 = 0;
        defender->stop_shotx7 = 0;
        defender->stop_shoty7 = 0;
        defender->trigger7 = 2;
    }
}

void check_hit13(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot6.x = 1465;
        defender->pos_shot6.y = 600;
        defender->zin2 = 0;
        defender->enemy_life2 -= 1;
        defender->count21 = 0;
        defender->count22 = 0;
        defender->count23 = 0;
        defender->count24 = 0;
        defender->stop_shotx6 = 0;
        defender->stop_shoty6 = 0;
        defender->trigger6 = 2;
    }
}

void check_hit12(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot5.x = 1130;
        defender->pos_shot5.y = 600;
        defender->zin2 = 0;
        defender->enemy_life2 -= 1;
        defender->count17 = 0;
        defender->count18 = 0;
        defender->count19 = 0;
        defender->count20 = 0;
        defender->stop_shotx5 = 0;
        defender->stop_shoty5 = 0;
        defender->trigger5 = 2;
    }
}

void check_hit11(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot4.x = 485;
        defender->pos_shot4.y = 800;
        defender->zin2 = 0;
        defender->enemy_life2 -= 1;
        defender->count13 = 0;
        defender->count14 = 0;
        defender->count15 = 0;
        defender->count16 = 0;
        defender->stop_shotx4 = 0;
        defender->stop_shoty4 = 0;
        defender->trigger4 = 2;
    }
}