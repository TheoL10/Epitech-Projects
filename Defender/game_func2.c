/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** my_defender
*/

#include "include/my.h"
#include "include/struct.h"

void animation3(defender_t *defender)
{
    if (defender->anim_ts5.left >= 1066)
        defender->anim_ts5.left = 0;
    if (defender->anim_ts6.left >= 1066)
        defender->anim_ts6.left = 0;
    if (defender->anim_ts7.left >= 1066)
        defender->anim_ts7.left = 0;
    if (defender->anim_sws.left >= 834)
        defender->anim_sws.left = 0;
    if (defender->anim_sws2.left >= 834)
        defender->anim_sws2.left = 0;
    if (defender->anim_sws3.left >= 834)
        defender->anim_sws3.left = 0;
    if (defender->anim_sws4.left >= 834)
        defender->anim_sws4.left = 0;
    if (defender->anim_sws5.left >= 834)
        defender->anim_sws5.left = 0;
    if (defender->anim_sws6.left >= 834)
        defender->anim_sws6.left = 0;
    if (defender->anim_sws7.left >= 834)
        defender->anim_sws7.left = 0;
}

void animation2(defender_t *defender)
{
    if (defender->anim_enemy.left >= 720)
        defender->anim_enemy.left = 0;
    if (defender->anim_shot.left >= 1020)
        defender->anim_shot.left = 0;
    if (defender->anim_shot2.left >= 1020)
        defender->anim_shot2.left = 0;
    if (defender->anim_shot3.left >= 1020)
        defender->anim_shot3.left = 0;
    if (defender->anim_shot4.left >= 1020)
        defender->anim_shot4.left = 0;
    if (defender->anim_shot5.left >= 1020)
        defender->anim_shot5.left = 0;
    if (defender->anim_ts.left >= 1066)
        defender->anim_ts.left = 0;
    if (defender->anim_ts2.left >= 1066)
        defender->anim_ts2.left = 0;
    if (defender->anim_ts3.left >= 1066)
        defender->anim_ts3.left = 0;
    if (defender->anim_ts4.left >= 1066)
        defender->anim_ts4.left = 0;
}

void animation1(defender_t *defender)
{
    defender->anim_enemy.left += 90;
    defender->anim_shot.left += 170;
    defender->anim_shot2.left += 170;
    defender->anim_shot3.left += 170;
    defender->anim_shot4.left += 170;
    defender->anim_shot5.left += 170;
    defender->anim_shot6.left += 170;
    defender->anim_shot7.left += 170;
    defender->anim_ts.left += 533;
    defender->anim_ts2.left += 533;
    defender->anim_ts3.left += 533;
    defender->anim_ts4.left += 533;
    defender->anim_ts5.left += 533;
    defender->anim_ts6.left += 533;
    defender->anim_ts7.left += 533;
    defender->anim_sws.left += 417;
    defender->anim_sws2.left += 417;
    defender->anim_sws3.left += 417;
    animation4(defender);
}

void enemy_shot7(defender_t *defender)
{
    if (defender->trigger7 == 1) {
        call_shot25(defender);
        call_shot26(defender);
    } rst_sh7(defender);
    if (defender->trigger7 == 3) {
        call_shot27(defender);
        call_shot28(defender);
    }
    enemy_shot14(defender);
}

void enemy_shot6(defender_t *defender)
{
    if (defender->trigger6 == 1) {
        call_shot21(defender);
        call_shot22(defender);
    } rst_sh6(defender);
    if (defender->trigger6 == 3) {
        call_shot23(defender);
        call_shot24(defender);
    }
    enemy_shot15(defender);
}