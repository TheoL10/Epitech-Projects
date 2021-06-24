/*
** EPITECH PROJECT, 2021
** build6
** File description:
** build6
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void tower25(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 1066 && defender->pos_ms.x <= 1181
        && defender->pos_ms.y >= 807 && defender->pos_ms.y <= 910
        && defender->choose == 1 && defender->place7 == 0
        && defender->gold >= 200) {
            defender->count_twer7 = 1;
            defender->gold -= 200;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place7 = 1;
        }
    } if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 1066 && defender->pos_ms.x <= 1181
        && defender->pos_ms.y >= 807 && defender->pos_ms.y <= 910
        && defender->choose2 == 1 && defender->place7 == 0
        && defender->gold >= 400) { defender->count_tesla7 = 1;
            defender->gold -= 400;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place7 = 1;
        }
    } tower26(defender);
}

void tower26(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 1066 && defender->pos_ms.x <= 1181
        && defender->pos_ms.y >= 807 && defender->pos_ms.y <= 910
        && defender->choose4 == 1 && defender->place7 == 0
        && defender->gold >= 350) {
            defender->count_slow7 = 1;
            defender->gold -= 350;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place7 = 1;
        }
    }
    if (defender->count_twer7 == 1 && defender->choose == 1)
        defender->first7 = 1;
    tower27(defender);
}

void tower27(defender_t *defender)
{
    const float pi = 3.14159265;
    float dx3 = defender->pos_ms.x - defender->pos_twer7.x;
    float dy3 = defender->pos_ms.y - defender->pos_twer7.y;
    float rotation3 = (atan2(dy3, dx3)) * 180 / pi;
    if (defender->first7 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->grass7, NULL);
        sfSprite_setOrigin(defender->twer7, defender->origin);
        sfSprite_setRotation(defender->twer7, rotation3 + 180);
        sfRenderWindow_drawSprite(defender->window, defender->shot7, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->twer7, NULL);
        call_shdir13(defender);
        call_shdir14(defender);
    }
    tower28(defender);
}

void tower28(defender_t *defender)
{
    if (defender->count_tesla7 == 1 && defender->choose2 == 1)
        defender->second7 = 1;
    if (defender->second7 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->tesla7, NULL);
    }
    if (defender->count_slow7 == 1 && defender->choose4 == 1)
        defender->third7 = 1;
    if (defender->third7 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->slow7, NULL);
    }
}