/*
** EPITECH PROJECT, 2020
** mouse
** File description:
** mouse
*/

#include "include/my.h"
#include "include/struct.h"

void setposition(runner_t *run)
{
    run->pos_mouse = sfMouse_getPositionRenderWindow(run->window);
    sfSprite_setPosition(run->mouse, (sfVector2f) {run->pos_mouse.x - 3,
    run->pos_mouse.y - 33});
    sfSprite_setPosition(run->play, run->pos_play);
    sfSprite_setPosition(run->back, run->pos_back);
    sfSprite_setPosition(run->life3, run->pos_life3);
    sfSprite_setPosition(run->life2, run->pos_life2);
    sfSprite_setPosition(run->life1, run->pos_life1);
    sfSprite_setPosition(run->set, run->pos_set);
    sfSprite_setPosition(run->fps1, run->pos_fps1);
    sfSprite_setPosition(run->fps2, run->pos_fps2);
    sfSprite_setPosition(run->fps3, run->pos_fps3);
    if (run->count_jump == 1)
        animation_jump(run);
    if (run->count_jump == 0)
        animation(run);
}