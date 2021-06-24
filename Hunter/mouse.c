/*
** EPITECH PROJECT, 2020
** mouse
** File description:
** mouse
*/

#include "include/my.h"
#include "include/struct.h"

void mouse_action(hunter_t *hunter)
{
    hunter->ms = sfMouse_getPositionRenderWindow(hunter->window);
    sfSprite_setPosition(hunter->sprite_mouse, (sfVector2f) {hunter->ms.x - 87,
                                                        hunter->ms.y - 87});
}