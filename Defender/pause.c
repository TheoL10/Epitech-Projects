/*
** EPITECH PROJECT, 2021
** pause.c
** File description:
** pause
*/

#include "include/my.h"
#include "include/struct.h"

void paus(defender_t *defender)
{
    sfRenderWindow_clear(defender->window, sfBlack);
    sfRenderWindow_drawSprite(defender->window, defender->paus, NULL);
    sfRenderWindow_drawSprite(defender->window, defender->resume, NULL);
    sfRenderWindow_drawSprite(defender->window, defender->menu, NULL);
    sfRenderWindow_drawSprite(defender->window, defender->esc, NULL);
    button4(defender);
}