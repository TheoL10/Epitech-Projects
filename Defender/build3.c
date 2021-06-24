/*
** EPITECH PROJECT, 2021
** build3
** File description:
** build3
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void tower10(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 750 && defender->pos_ms.x <= 865
        && defender->pos_ms.y >= 609 && defender->pos_ms.y <= 712
        && defender->choose4 == 1 && defender->place3 == 0
        && defender->gold >= 350) {
            defender->count_slow3 = 1;
            defender->gold -= 350;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place3 = 1;

        }
    }
    if (defender->count_twer3 == 1 && defender->choose == 1)
        defender->first3 = 1;
    tower11(defender);
}

void tower11(defender_t *defender)
{
    const float pi = 3.14159265;
    float dx = defender->pos_ms.x - defender->pos_twer3.x;
    float dy = defender->pos_ms.y - defender->pos_twer3.y;
    float rotation = (atan2(dy, dx)) * 180 / pi;
    if (defender->first3 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->grass4, NULL);
        sfSprite_setOrigin(defender->twer3, defender->origin);
        sfSprite_setRotation(defender->twer3, rotation + 180);
        sfRenderWindow_drawSprite(defender->window, defender->shot3, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->twer3, NULL);
        call_shdir5(defender);
        call_shdir6(defender);
    }
    tower12(defender);
}

void tower12(defender_t *defender)
{
    if (defender->count_tesla3 == 1 && defender->choose2 == 1)
        defender->second3 = 1;
    if (defender->second3 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->tesla3, NULL);
    }
    if (defender->count_slow3 == 1 && defender->choose4 == 1)
        defender->third3 = 1;
    if (defender->third3 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->slow3, NULL);
    }
    tower13(defender);
}

void tower13(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 414 && defender->pos_ms.x <= 529
        && defender->pos_ms.y >= 807 && defender->pos_ms.y <= 910
        && defender->choose == 1 && defender->place4 == 0
        && defender->gold >= 200) {
            defender->count_twer4 = 1;
            defender->gold -= 200;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place4 = 1;
        }
    } if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 414 && defender->pos_ms.x <= 529
        && defender->pos_ms.y >= 807 && defender->pos_ms.y <= 910
        && defender->choose2 == 1 && defender->place4 == 0
        && defender->gold >= 400) { defender->count_tesla4 = 1;
            defender->gold -= 400;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place4 = 1;
        }
    } tower14(defender);
}

void tower14(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 414 && defender->pos_ms.x <= 529
        && defender->pos_ms.y >= 807 && defender->pos_ms.y <= 910
        && defender->choose4 == 1 && defender->place4 == 0
        && defender->gold >= 350) {
            defender->count_slow4 = 1;
            defender->gold -= 350;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place4 = 1;
        }
    }
    if (defender->count_twer4 == 1 && defender->choose == 1)
        defender->first4 = 1;
    tower15(defender);
}