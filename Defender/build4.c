/*
** EPITECH PROJECT, 2021
** build4
** File description:
** build4
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void tower15(defender_t *defender)
{
    const float pi = 3.14159265;
    float dx2 = defender->pos_ms.x - defender->pos_twer4.x;
    float dy2 = defender->pos_ms.y - defender->pos_twer4.y;
    float rotation2 = (atan2(dy2, dx2)) * 180 / pi;
    if (defender->first4 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->grass2, NULL);
        sfSprite_setOrigin(defender->twer4, defender->origin);
        sfSprite_setRotation(defender->twer4, rotation2+ 180);
        sfRenderWindow_drawSprite(defender->window, defender->shot4, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->twer4, NULL);
        call_shdir7(defender);
        call_shdir8(defender);
    }
    tower16(defender);
}

void tower16(defender_t *defender)
{
    if (defender->count_tesla4 == 1 && defender->choose2 == 1)
        defender->second4 = 1;
    if (defender->second4 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->tesla4, NULL);
    }
    if (defender->count_slow4 == 1 && defender->choose4 == 1)
        defender->third4 = 1;
    if (defender->third4 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->slow4, NULL);
    }
    tower17(defender);
}

void tower17(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 1066 && defender->pos_ms.x <= 1181
        && defender->pos_ms.y >= 556 && defender->pos_ms.y <= 659
        && defender->choose == 1 && defender->place5 == 0
        && defender->gold >= 200) {
            defender->count_twer5 = 1;
            defender->gold -= 200;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place5 = 1;
        }
    } if (sfMouse_isButtonPressed(sfMouseLeft)) {
      
        if (defender->pos_ms.x >= 1066 && defender->pos_ms.x <= 1181
        && defender->pos_ms.y >= 556 && defender->pos_ms.y <= 659
        && defender->choose2 == 1 && defender->place5 == 0
        && defender->gold >= 400) { defender->count_tesla5 = 1;
            defender->gold -= 400;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place5 = 1;
        }
    } tower18(defender);
}

void tower18(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 1066 && defender->pos_ms.x <= 1181
        && defender->pos_ms.y >= 556 && defender->pos_ms.y <= 659
        && defender->choose4 == 1 && defender->place5 == 0
        && defender->gold >= 350) {
            defender->count_slow5 = 1;
            defender->gold -= 350;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place5 = 1;
        }
    }
    if (defender->count_twer5 == 1 && defender->choose == 1)
        defender->first5 = 1;
    tower19(defender);
}

void tower19(defender_t *defender)
{
    const float pi = 3.14159265;
    float dx = defender->pos_ms.x - defender->pos_twer5.x;
    float dy = defender->pos_ms.y - defender->pos_twer5.y;
    float rotation = (atan2(dy, dx)) * 180 / pi;

    if (defender->first5 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->grass6, NULL);
        sfSprite_setOrigin(defender->twer5, defender->origin);
        sfSprite_setRotation(defender->twer5, rotation + 180);
        sfRenderWindow_drawSprite(defender->window, defender->shot5, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->twer5, NULL);
        call_shdir9(defender);
        call_shdir10(defender);
    }
    tower20(defender);
}