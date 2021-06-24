/*
** EPITECH PROJECT, 2021
** button2
** File description:
** button2
*/

#include "include/my.h"
#include "include/struct.h"

void button6(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_arrow.x >= 0 && defender->pos_ms.x <= 114
        && defender->pos_ms.y >= 0
        && defender->pos_ms.y <= 93)
            defender->count_menu = 0;
    }
}

void button7(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 1678 && defender->pos_ms.x <= 1920
        && defender->pos_ms.y >= 300
        && defender->pos_ms.y <= 476) {
            defender->choose = 1;
            defender->choose2 = 0;
            defender->choose3 = 0;
            defender->choose4 = 0;
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 1678 && defender->pos_ms.x <= 1920
        && defender->pos_ms.y >= 483
        && defender->pos_ms.y <= 651) {
            defender->choose = 0;
            defender->choose2 = 1;
            defender->choose3 = 0;
            defender->choose4 = 0;
        }
    } button8(defender);
}

void button8(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 1678 && defender->pos_ms.x <= 1920
        && defender->pos_ms.y >= 658
        && defender->pos_ms.y <= 829) {
            defender->choose = 0;
            defender->choose2 = 0;
            defender->choose3 = 1;
            defender->choose4 = 0;
        }
    }
    if (defender->choose3 == 1)
        defender->count_rock = 1;
    if (defender->count_rock == 1)
        sfRenderWindow_drawSprite(defender->window, defender->rock, NULL);
    button9(defender);
}

void button9(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 1678 && defender->pos_ms.x <= 1920
        && defender->pos_ms.y >= 836
        && defender->pos_ms.y <= 1006) {
            defender->choose = 0;
            defender->choose2 = 0;
            defender->choose3 = 0;
            defender->choose4 = 1;
        }
    }
}

void button10(defender_t *defender)
{
    if (defender->choose == 1)
        sfRenderWindow_drawSprite(defender->window, defender->slt1, NULL);
    if (defender->choose2 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->slt2, NULL);
    if (defender->choose3 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->slt3, NULL);
    if (defender->choose4 == 1)
        sfRenderWindow_drawSprite(defender->window, defender->slt4, NULL);
}