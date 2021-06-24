/*
** EPITECH PROJECT, 2021
** button
** File description:
** button
*/

#include "include/my.h"
#include "include/struct.h"

void button(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 830 && defender->pos_ms.x <= 1108
        && defender->pos_ms.y >= 500
        && defender->pos_ms.y <= 569)
            defender->count_menu = 1;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1
    && defender->count_menu == 0) {
        if (defender->pos_ms.x >= 830 && defender->pos_ms.x <= 1108
        && defender->pos_ms.y >= 640
        && defender->pos_ms.y <= 709)
            sfRenderWindow_close(defender->window);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1
    && defender->count_menu == 0) {
        if (defender->pos_ms.x >= 830 && defender->pos_ms.x <= 1108
        && defender->pos_ms.y >= 780
        && defender->pos_ms.y <= 849)
            defender->count_menu = 2;
    }
}

void button2(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1
    && defender->count_menu == 2) {
        if (defender->pos_arrow.x >= 0 && defender->pos_ms.x <= 114
        && defender->pos_ms.y >= 0
        && defender->pos_ms.y <= 93)
            defender->count_menu = 0;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 383 && defender->pos_ms.x <= 658
        && defender->pos_ms.y >= 500
        && defender->pos_ms.y <= 558)
            sfRenderWindow_setFramerateLimit(defender->window, 60);
    } if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 783 && defender->pos_ms.x <= 1058
        && defender->pos_ms.y >= 500
        && defender->pos_ms.y <= 558) {
            sfRenderWindow_setFramerateLimit(defender->window, 120);
            defender->count_fps = 1;
        }
    } button3(defender);
}

void button3(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 1183 && defender->pos_ms.x <= 1458
        && defender->pos_ms.y >= 500
        && defender->pos_ms.y <= 558) {
            sfRenderWindow_setFramerateLimit(defender->window, 180);
            defender->count_fps = 1;
        }
    }
}

void button4(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 550 && defender->pos_ms.x <= 776
        && defender->pos_ms.y >= 500
        && defender->pos_ms.y <= 588)
            defender->count_menu = 0;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 830 && defender->pos_ms.x <= 1056
        && defender->pos_ms.y >= 500
        && defender->pos_ms.y <= 588) {
            defender->count_menu = 1;
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 1110 && defender->pos_ms.x <= 1336
        && defender->pos_ms.y >= 500
        && defender->pos_ms.y <= 588) {
            sfRenderWindow_close(defender->window);
        }
    }
}

void button5(defender_t *defender)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (defender->pos_ms.x >= 1810 && defender->pos_ms.x <= 1920
        && defender->pos_ms.y >= 880
        && defender->pos_ms.y <= 1080)
            defender->count_menu = 4;
    }
}