/*
** EPITECH PROJECT, 2021
** kill
** File description:
** kill
*/

#include "include/my.h"
#include "include/struct.h"

void kill(runner_t *run)
{
    sfMusic_destroy(run->jumping);
    sfMusic_destroy(run->oof);
    sfMusic_destroy(run->mine);
    sfSprite_destroy(run->mouse);
    sfTexture_destroy(run->text_mouse);
}