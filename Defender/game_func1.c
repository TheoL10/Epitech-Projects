/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** my_defender
*/

#include "include/my.h"
#include "include/struct.h"

void enemy_shot5(defender_t *defender)
{
    if (defender->trigger5 == 1) {
        call_shot17(defender);
        call_shot18(defender);
    } rst_sh5(defender);
    if (defender->trigger5 == 3) {
        call_shot19(defender);
        call_shot20(defender);
    }
    enemy_shot8(defender);
}

void enemy_shot4(defender_t *defender)
{
    if (defender->trigger4 == 1) {
        call_shot13(defender);
        call_shot14(defender);
    } rst_sh4(defender);
    if (defender->trigger4 == 3) {
        call_shot15(defender);
        call_shot16(defender);
    }
    enemy_shot9(defender);
}

void enemy_shot3(defender_t *defender)
{
    if (defender->trigger3 == 1) {
        call_shot9(defender);
        call_shot10(defender);
    } rst_sh3(defender);
    if (defender->trigger3 == 3) {
        call_shot11(defender);
        call_shot12(defender);
    }
    enemy_shot11(defender);
}

void enemy_shot2(defender_t *defender)
{
    if (defender->trigger2 == 1) {
        call_shot5(defender);
        call_shot6(defender);
    } rst_sh2(defender);
    if (defender->trigger2 == 3) {
        call_shot7(defender);
        call_shot8(defender);
    }
    enemy_shot12(defender);
}

void enemy_shot(defender_t *defender)
{
    if (defender->trigger == 1) {
        call_sh1(defender);
        call_sh2(defender);
    }
    rst_sh1(defender);
    if (defender->trigger == 3) {
        call_sh3(defender);
        call_sh4(defender);
    }
    enemy_shot13(defender);
}