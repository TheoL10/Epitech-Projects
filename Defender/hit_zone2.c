/*
** EPITECH PROJECT, 2021
** hit_zone2
** File description:
** hit_zone2
*/

#include "include/my.h"
#include "include/struct.h"

void check_hit5(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot5.x = 1130;
        defender->pos_shot5.y = 600;
        defender->zin = 0;
        defender->enemy_life -= 1;
        defender->count17 = 0;
        defender->count18 = 0;
        defender->count19 = 0;
        defender->count20 = 0;
        defender->stop_shotx5 = 0;
        defender->stop_shoty5 = 0;
        defender->trigger5 = 2;
    }
}

void check_hit4(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot4.x = 485;
        defender->pos_shot4.y = 800;
        defender->zin = 0;
        defender->enemy_life -= 1;
        defender->count13 = 0;
        defender->count14 = 0;
        defender->count15 = 0;
        defender->count16 = 0;
        defender->stop_shotx4 = 0;
        defender->stop_shoty4 = 0;
        defender->trigger4 = 2;
    }
}

void check_hit3(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot3.x = 805;
        defender->pos_shot3.y = 650;
        defender->zin = 0;
        defender->enemy_life -= 1;
        defender->count9 = 0;
        defender->count10 = 0;
        defender->count11 = 0;
        defender->count12 = 0;
        defender->stop_shotx3 = 0;
        defender->stop_shoty3 = 0;
        defender->trigger3 = 2;
    }
}

void check_hit2(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot2.x = 815;
        defender->pos_shot2.y = 420;
        defender->zin = 0;
        defender->enemy_life -= 1;
        defender->count5 = 0;
        defender->count6 = 0;
        defender->count7 = 0;
        defender->count8 = 0;
        defender->stop_shotx2 = 0;
        defender->stop_shoty2 = 0;
        defender->trigger2 = 2;
    }
}

void check_hit(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi)
{
    if (pos_sprite1.x >= pos_sprite2.x && pos_sprite1.x <= pos_sprite2.x + 68
    && pos_sprite1.y >= pos_sprite2.y && pos_sprite1.y <= pos_sprite2.y + 100
    && zbi == 1) {
        defender->pos_shot.x = 485;
        defender->pos_shot.y = 270;
        defender->zin = 0;
        defender->enemy_life -= 1;
        defender->count = 0;
        defender->count2 = 0;
        defender->count3 = 0;
        defender->count4 = 0;
        defender->stop_shotx = 0;
        defender->stop_shoty = 0;
        defender->trigger = 2;
    }
}