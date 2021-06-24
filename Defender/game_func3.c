/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** my_defender
*/

#include "include/my.h"
#include "include/struct.h"

void animation4(defender_t *defender)
{
    defender->anim_sws4.left += 417;
    defender->anim_sws5.left += 417;
    defender->anim_sws6.left += 417;
    defender->anim_sws7.left += 417;
    defender->anim_mj.top += 89;
    if (defender->anim_mj.top >= 534)
        defender->anim_mj.top = 0;
    animation2(defender);
    animation3(defender);
}