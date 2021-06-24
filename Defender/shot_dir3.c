/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** enemy_shot
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void call_shdir12(defender_t *defender)
{
    if (defender->trigger6 == 2) {
        const float pi2 = 3.14159265;
        defender->di6 = defender->pos_ms.x - defender->pos_shot6.x;
        defender->diy6 = defender->pos_ms.y - defender->pos_shot6.y;
        float rotation2 = (atan2(defender->diy6, defender->di6)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot6, defender->origin_shot6);
        sfSprite_setRotation(defender->shot6, rotation2 + 180);
        defender->dx13 = defender->di6 * 5;
        defender->dy13 = defender->diy6 * 5;
        defender->dx14 = defender->di6;
        defender->dy14 = defender->diy6;
        defender->pos21 = (defender->pos_shot6.x - defender->dx14);
        defender->pos22 = (defender->pos_shot6.x + defender->dx14);
        defender->pos23 = (defender->pos_shot6.y + defender->dy14);
        defender->pos24 = (defender->pos_shot6.y - defender->dy14);
        defender->trigger6 = 3;
    }
}

void call_shdir11(defender_t *defender)
{
    if (defender->trigger6 == 0) {
        const float pi2 = 3.14159265;
        defender->di6 = defender->pos_ms.x - defender->pos_shot6.x;
        defender->diy6 = defender->pos_ms.y - defender->pos_shot6.y;
        float rotation2 = (atan2(defender->diy6, defender->di6)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot6, defender->origin_shot4);
        sfSprite_setRotation(defender->shot6, rotation2 + 180);
        defender->dx13 = defender->di6 * 40;
        defender->dy13 = defender->diy6 * 40;
        defender->dx14 = defender->di6;
        defender->dy14 = defender->diy6;
        defender->pos21 = (defender->pos_shot6.x - defender->dx14);
        defender->pos22 = (defender->pos_shot6.x + defender->dx14);
        defender->pos23 = (defender->pos_shot6.y + defender->dy14);
        defender->pos24 = (defender->pos_shot6.y - defender->dy14);
        defender->trigger6 = 1;
    }
}

void call_shdir10(defender_t *defender)
{
    if (defender->trigger5 == 2) {
        const float pi2 = 3.14159265;
        defender->di5 = defender->pos_ms.x - defender->pos_shot5.x;
        defender->diy5 = defender->pos_ms.y - defender->pos_shot5.y;
        float rotation2 = (atan2(defender->diy5, defender->di5)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot5, defender->origin_shot4);
        sfSprite_setRotation(defender->shot5, rotation2 + 180);
        defender->dx11 = defender->di5 * 5;
        defender->dy11 = defender->diy5 * 5;
        defender->dx12 = defender->di5;
        defender->dy12 = defender->diy5;
        defender->pos17 = (defender->pos_shot5.x - defender->dx12);
        defender->pos18 = (defender->pos_shot5.x + defender->dx12);
        defender->pos19 = (defender->pos_shot5.y + defender->dy12);
        defender->pos20 = (defender->pos_shot5.y - defender->dy12);
        defender->trigger5 = 3;
    }
}

void call_shdir9(defender_t *defender)
{
    if (defender->trigger5 == 0) {
        const float pi2 = 3.14159265;
        defender->di5 = defender->pos_ms.x - defender->pos_shot5.x;
        defender->diy5 = defender->pos_ms.y - defender->pos_shot5.y;
        float rotation2 = (atan2(defender->diy5, defender->di5)) * 180 /
        pi2;
        sfSprite_setOrigin(defender->shot5, defender->origin_shot3);
        sfSprite_setRotation(defender->shot5, rotation2 + 180);
        defender->dx11 = defender->di5 * 40;
        defender->dy11 = defender->diy5 * 40;
        defender->dx12 = defender->di5;
        defender->dy12 = defender->diy5;
        defender->pos17 = (defender->pos_shot5.x - defender->dx12);
        defender->pos18 = (defender->pos_shot5.x + defender->dx12);
        defender->pos19 = (defender->pos_shot5.y + defender->dy12);
        defender->pos20 = (defender->pos_shot5.y - defender->dy12);
        defender->trigger5 = 1;
    }
}

void call2(defender_t *defender)
{
    defender->pos_text.y = -25;
    sfText_setFont(defender->scoros, defender->font);
    sfText_setPosition(defender->scoros, defender->pos_text);
    set_texture(defender);
    sfMusic_play(defender->loop);
    defender->enemy_life = 3;
    defender->enemy_life2 = 3;
    defender->count_path2 = -1;
    defender->gold = 200;
    game_loop(defender);
}