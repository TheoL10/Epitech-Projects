/*
** EPITECH PROJECT, 2021
** vie
** File description:
** vie
*/

#include "include/my.h"
#include "include/struct.h"

void vie(defender_t *defender)
{
    if (defender->count_vie == 1)
        sfRenderWindow_drawSprite(defender->window, defender->vie2, NULL);
    if (defender->count_vie == 2)
        sfRenderWindow_drawSprite(defender->window, defender->vie3, NULL);
    if (defender->count_vie == 3) {
        sfRenderWindow_clear(defender->window, sfBlack);
        sfRenderWindow_drawSprite(defender->window, defender->fin, NULL);
    }
}