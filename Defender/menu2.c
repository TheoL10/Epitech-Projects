/*
** EPITECH PROJECT, 2021
** menu
** File description:
** menu2
*/

#include "include/my.h"
#include "include/struct.h"

void menu6(defender_t *defender)
{
    menu3(defender);
    menu4(defender);
    tower(defender);
    check_hit(defender, defender->pos_shot, defender->pos_enemy,
    defender->first);
    check_hit2(defender, defender->pos_shot2, defender->pos_enemy,
    defender->first2);
    check_hit3(defender, defender->pos_shot3, defender->pos_enemy,
    defender->first3);
    check_hit4(defender, defender->pos_shot4, defender->pos_enemy,
    defender->first4);
    check_hit5(defender, defender->pos_shot5, defender->pos_enemy,
    defender->first5);
    check_hit6(defender, defender->pos_shot6, defender->pos_enemy,
    defender->first6);
    check_hit7(defender, defender->pos_shot7, defender->pos_enemy,
    defender->first7);
    check_hit8(defender, defender->pos_shot, defender->pos_mj,
    defender->first);
}

void menu7(defender_t *defender)
{
    if (defender->enemy_life == 0 && defender->zin == 0) {
        defender->gold += 150;
        defender->count_path = 0;
        defender->pos_enemy.x = 930;
        defender->pos_enemy.y = -150;
        defender->cnt_enemy = 0;
        defender->count_kill += 1;
        if (defender->count_kill == 3) {
            defender->tacapte = defender->tacapte + 1;
            defender->count_kill = 0;
        }
        defender->enemy_life = defender->tacapte + 3;
        defender->zin = 1;
    }
}

void menu8(defender_t *defender)
{
    if (defender->enemy_life2 == 0 && defender->zin2 == 0) {
        defender->gold += 200;
        defender->count_path2 = 0;
        defender->pos_mj.x = 930;
        defender->pos_mj.y = -150;
        defender->cnt_enemy2 = 0;
        defender->count_kill2 += 1;
        defender->enemy_life2 = 3;
        defender->zin2 = 1;
    }
    sfRenderWindow_drawSprite(defender->window, defender->m_build, NULL);
    sfRenderWindow_drawText(defender->window, defender->scoros, NULL);
    sfRenderWindow_drawSprite(defender->window, defender->coin, NULL);
    sfRenderWindow_drawSprite(defender->window, defender->up, NULL);
    button10(defender);
    vie(defender);
}