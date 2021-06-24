/*
** EPITECH PROJECT, 2020
** button
** File description:
** button
*/

#include "include/struct.h"
#include "include/my.h"

void button(hunter_t *hunter)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) == 1 && hunter->menu == 0)) {
        if (hunter->ms.x >= 830 && hunter->ms.x <= 1108 && hunter->ms.y >= 360
        && hunter->ms.y <= 429) {
            hunter->menu = 1;
            sfClock_restart(hunter->move);
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (hunter->ms.x >= 830 && hunter->ms.x <= 1108 && hunter->ms.y >= 480
        && hunter->ms.y <= 549)
            sfRenderWindow_close(hunter->window);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (hunter->ms.x >= 830 && hunter->ms.x <= 1108 && hunter->ms.y >= 600
        && hunter->ms.y <= 669)
            hunter->menu = 2;
    }
}

void button2(hunter_t *hunter)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (hunter->ms.x >= 383 && hunter->ms.x <= 658 &&
        hunter->ms.y >= 500 && hunter->ms.y <= 558)
            sfRenderWindow_setFramerateLimit(hunter->window, 60);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (hunter->ms.x >= 783 && hunter->ms.x <= 1058 &&
        hunter->ms.y >= 500 && hunter->ms.y <= 558)
            sfRenderWindow_setFramerateLimit(hunter->window, 120);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (hunter->ms.x >= 1183 && hunter->ms.x <= 1458 &&
        hunter->ms.y >= 500 && hunter->ms.y <= 558)
            sfRenderWindow_setFramerateLimit(hunter->window, 180);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (hunter->ms.x >= 0 && hunter->ms.x <= 300 &&
        hunter->ms.y >= 0 && hunter->ms.y <= 226)
            hunter->menu = 0;
    }
}