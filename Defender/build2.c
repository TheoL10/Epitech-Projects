/*
** EPITECH PROJECT, 2021
** build2
** File description:
** build2
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void tower5(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 750 && defender->pos_ms.x <= 865
        && defender->pos_ms.y >= 369 && defender->pos_ms.y <= 472
        && defender->choose == 1 && defender->place2 == 0
        && defender->gold >= 200) {
            defender->count_twer2 = 1;
            defender->gold -= 200;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place2 = 1;
        }
    } if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 750 && defender->pos_ms.x <= 865
        && defender->pos_ms.y >= 369 && defender->pos_ms.y <= 472
        && defender->choose2 == 1 && defender->place2 == 0
        && defender->gold >= 400) { defender->count_tesla2 = 1;
            defender->gold -= 400;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place2 = 1;
        }
    } tower6(defender);
}

void tower6(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 750 && defender->pos_ms.x <= 865
        && defender->pos_ms.y >= 369 && defender->pos_ms.y <= 472
        && defender->choose4 == 1 && defender->place2 == 0
        && defender->gold >= 350) {
            defender->count_slow2 = 1;
            defender->gold -= 350;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place2 = 1;
        }
    }
    if (defender->count_twer2 == 1 && defender->choose == 1)
        defender->first2 = 1;
    tower7(defender);
}

void tower7(defender_t *defender)
{
    const float pi = 3.14159265;
    float dx = defender->pos_ms.x - defender->pos_twer2.x;
    float dy = defender->pos_ms.y - defender->pos_twer2.y;
    float rotation = (atan2(dy, dx)) * 180 / pi;
    if (defender->first2 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->grass3, NULL);
        sfSprite_setOrigin(defender->twer2, defender->origin);
        sfSprite_setRotation(defender->twer2, rotation + 180);
        sfRenderWindow_drawSprite(defender->window, defender->shot2, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->twer2, NULL);
        call_shdir3(defender);
        call_shdir4(defender);
    }
    tower8(defender);
}

void tower8(defender_t *defender)
{
    if (defender->count_tesla2 == 1 && defender->choose2 == 1)
        defender->second2 = 1;
    if (defender->second2 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->tesla2, NULL);
    }
    if (defender->count_slow2 == 1 && defender->choose4 == 1)
        defender->third2 = 1;
    if (defender->third2 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->slow2, NULL);
    tower9(defender);
}

void tower9(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 750 && defender->pos_ms.x <= 865
        && defender->pos_ms.y >= 609 && defender->pos_ms.y <= 712
        && defender->choose == 1 && defender->place3 == 0
        && defender->gold >= 200) { defender->count_twer3 = 1;
            defender->gold -= 200;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place3 = 1;
        }
    } if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 750 && defender->pos_ms.x <= 865
        && defender->pos_ms.y >= 609 && defender->pos_ms.y <= 712
        && defender->choose2 == 1 && defender->place3 == 0
        && defender->gold >= 400) { defender->count_tesla3 = 1;
            defender->gold -= 400;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place3 = 1;

        }
    } tower10(defender);
}