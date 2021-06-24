/*
** EPITECH PROJECT, 2020
** button
** File description:
** button
*/

#include "include/my.h"
#include "include/struct.h"

void button(runner_t *run)
{
    if ((sfMouse_isButtonPressed(sfMouseLeft) == 1 && run->count == 0)) {
        if (run->pos_mouse.x >= 830 && run->pos_mouse.x <= 1108
        && run->pos_mouse.y >= 420
        && run->pos_mouse.y <= 489) {
            run->count = 1;
            sfClock_restart(run->move);
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (run->pos_mouse.x >= 830 && run->pos_mouse.x <= 1108
        && run->pos_mouse.y >= 560
        && run->pos_mouse.y <= 629)
            sfRenderWindow_close(run->window);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (run->pos_mouse.x >= 830 && run->pos_mouse.x <= 1108
        && run->pos_mouse.y >= 700
        && run->pos_mouse.y <= 769)
            run->count = 3;
    }
}

void button2(runner_t *run)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (run->pos_mouse.x >= 0 && run->pos_mouse.x <= 300 &&
            run->pos_mouse.y >= 0 && run->pos_mouse.y <= 226)
            run->count = 0;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (run->pos_mouse.x >= 383 && run->pos_mouse.x <= 658
        && run->pos_mouse.y >= 500
        && run->pos_mouse.y <= 558)
            sfRenderWindow_setFramerateLimit(run->window, 60);
    }
    button3(run);
}

void button3(runner_t *run)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (run->pos_mouse.x >= 383 && run->pos_mouse.x <= 658
        && run->pos_mouse.y >= 783
        && run->pos_mouse.y <= 841)
            sfRenderWindow_setFramerateLimit(run->window, 120);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1) {
        if (run->pos_mouse.x >= 383 && run->pos_mouse.x <= 658
        && run->pos_mouse.y >= 1183
        && run->pos_mouse.y <= 1241)
            sfRenderWindow_setFramerateLimit(run->window, 180);
    }
}