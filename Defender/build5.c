/*
** EPITECH PROJECT, 2021
** build5
** File description:
** build5
*/

#include "include/my.h"
#include "include/struct.h"
#include <math.h>

void tower20(defender_t *defender)
{
    if (defender->count_tesla5 == 1 && defender->choose2 == 1)
        defender->second5 = 1;
    if (defender->second5 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->tesla5, NULL);
    }
    if (defender->count_slow5 == 1 && defender->choose4 == 1)
        defender->third5 = 1;
    if (defender->third5 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->slow5, NULL);
    }
    tower21(defender);
}

void tower21(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 1385 && defender->pos_ms.x <= 1500
        && defender->pos_ms.y >= 369 && defender->pos_ms.y <= 472
        && defender->choose == 1 && defender->place6 == 0
        && defender->gold >= 200) {
            defender->count_twer6 = 1;
            defender->gold -= 200;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place6 = 1;
        }
    } if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 1385 && defender->pos_ms.x <= 1500
        && defender->pos_ms.y >= 369 && defender->pos_ms.y <= 472
        && defender->choose2 == 1 && defender->place6 == 0
        && defender->gold >= 400) { defender->count_tesla6 = 1;
            defender->gold -= 400;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place6 = 1;
        }
    } tower22(defender);
}

void tower22(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (defender->pos_ms.x >= 1385 && defender->pos_ms.x <= 1500
        && defender->pos_ms.y >= 369 && defender->pos_ms.y <= 472
        && defender->choose4 == 1 && defender->place6 == 0
        && defender->gold >= 350) {
            defender->count_slow6 = 1;
            defender->gold -= 350;
            sfRenderWindow_setMouseCursorVisible(defender->window, sfTrue);
            defender->place6 = 1;
        }
    }
    if (defender->count_twer6 == 1 && defender->choose == 1)
        defender->first6 = 1;
    tower23(defender);
}

void tower23(defender_t *defender)
{
    const float pi = 3.14159265;
    float dx2 = defender->pos_ms.x - defender->pos_twer6.x;
    float dy2 = defender->pos_ms.y - defender->pos_twer6.y;
    float rotation2 = (atan2(dy2, dx2)) * 180 / pi;
    if (defender->first6 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->grass5, NULL);
        sfSprite_setOrigin(defender->twer6, defender->origin);
        sfSprite_setRotation(defender->twer6, rotation2 + 180);
        sfRenderWindow_drawSprite(defender->window, defender->shot6, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->twer6, NULL);
        call_shdir11(defender);
        call_shdir12(defender);
    }
    tower24(defender);
}

void tower24(defender_t *defender)
{
    if (defender->count_tesla6 == 1 && defender->choose2 == 1)
        defender->second6 = 1;
    if (defender->second6 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->tesla6, NULL);
    }
    if (defender->count_slow6 == 1 && defender->choose4 == 1)
        defender->third6 = 1;
    if (defender->third6 == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->slow6, NULL);
    }
    tower25(defender);
}