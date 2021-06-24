/*
** EPITECH PROJECT, 2021
** build
** File description:
** build
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void build(defender_t *defender)
{
    if ((defender->pos_ms.x >= 414 && defender->pos_ms.x <= 529
    && defender->pos_ms.y >= 214 && defender->pos_ms.y <= 317)
    || (defender->pos_ms.x >= 750 && defender->pos_ms.x <= 865
    && defender->pos_ms.y >= 369 && defender->pos_ms.y <= 472)
    || (defender->pos_ms.x >= 750 && defender->pos_ms.x <= 865
    && defender->pos_ms.y >= 609 && defender->pos_ms.y <= 712)
    || (defender->pos_ms.x >= 414 && defender->pos_ms.x <= 529
    && defender->pos_ms.y >= 807 && defender->pos_ms.y <= 910)
    || (defender->pos_ms.x >= 1066 && defender->pos_ms.x <= 1181
    && defender->pos_ms.y >= 556 && defender->pos_ms.y <= 659)
    || (defender->pos_ms.x >= 1385 && defender->pos_ms.x <= 1500
    && defender->pos_ms.y >= 369 && defender->pos_ms.y <= 472)
    || (defender->pos_ms.x >= 1066 && defender->pos_ms.x <= 1181
    && defender->pos_ms.y >= 807 && defender->pos_ms.y <= 910)) {
        sfRenderWindow_drawSprite(defender->window, defender->cs, NULL);
        sfRenderWindow_setMouseCursorVisible(defender->window, sfFalse);
    }
    else
        sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
}

void tower(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 414 && defender->pos_ms.x <= 529
        && defender->pos_ms.y >= 214 && defender->pos_ms.y <= 317
        && defender->choose == 1 && defender->place1 == 0
        && defender->gold >= 200) { defender->count_twer = 1;
            defender->gold -= 200;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place1 = 1;
        }
    } if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 414 && defender->pos_ms.x <= 529
        && defender->pos_ms.y >= 214 && defender->pos_ms.y <= 317
        && defender->choose2 == 1 && defender->place1 == 0
        && defender->gold >= 400) {
            defender->count_tesla = 1;
            defender->gold -= 400;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place1 = 1;
        }
    } tower2(defender);
}

void tower2(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 414 && defender->pos_ms.x <= 529
        && defender->pos_ms.y >= 214 && defender->pos_ms.y <= 317
        && defender->choose4 == 1 && defender->place1 == 0
        && defender->gold >= 350) {
            defender->count_slow = 1;
            defender->gold -= 350;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place1 = 1;
        }
    }
    if (defender->count_twer == 1 && defender->choose == 1)
        defender->first = 1;
    tower3(defender);
}

void tower3(defender_t *defender)
{
    float dx = defender->pos_ms.x - defender->pos_twer1.x;
    float dy = defender->pos_ms.y - defender->pos_twer1.y;
    const float pi = 3.14159265;
    float rotation = (atan2(dy, dx)) * 180 / pi;
    if (defender->first == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->grass1, NULL);
        sfSprite_setOrigin(defender->twer1, defender->origin);
        sfSprite_setRotation(defender->twer1, rotation + 180);
        sfRenderWindow_drawSprite(defender->window, defender->shot, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->twer1, NULL);
        call_shdir1(defender);
        call_shdir2(defender);
    }
    tower4(defender);
}

void tower4(defender_t *defender)
{
    if (defender->count_tesla == 1 && defender->choose2 == 1)
        defender->second = 1;
    if (defender->second == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->tesla1, NULL);
    }
    if (defender->count_slow == 1 && defender->choose4 == 1)
        defender->third = 1;
    if (defender->third == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->slow1, NULL);
    }
    tower5(defender);
}