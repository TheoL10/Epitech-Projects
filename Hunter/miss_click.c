/*
** EPITECH PROJECT, 2020
** miss_click
** File description:
** miss_click
*/

#include "include/my.h"
#include "include/struct.h"

void miss_click(hunter_t *hunter)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && hunter->pos.x >= 0
    && hunter->vie == 0) {
        if (!(hunter->ms.x <= hunter->pos.x + 153
        && hunter->ms.x >= hunter->pos.x
        && hunter->ms.y <= hunter->pos.y + 134
        && hunter->ms.y >= hunter->pos.y))
            hunter->vie++;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)
    && hunter->pos.x >= 0 && hunter->vie == 1 && hunter->life == 1) {
        if (!(hunter->ms.x <= hunter->pos.x + 153
        && hunter->ms.x >= hunter->pos.x
        && hunter->ms.y <= hunter->pos.y + 134
        && hunter->ms.y >= hunter->pos.y))
            hunter->vie++;
    }
    miss_click2(hunter);
}

void miss_click2(hunter_t *hunter)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
    && hunter->pos.x >= 0 && hunter->vie == 2 && hunter->life == 2) {
        if (!(hunter->ms.x <= hunter->pos.x + 153
        && hunter->ms.x >= hunter->pos.x
        && hunter->ms.y <= hunter->pos.y + 134
        && hunter->ms.y >= hunter->pos.y))
            hunter->vie++;
    }
}