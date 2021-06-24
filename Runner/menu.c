/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include "include/my.h"
#include "include/struct.h"

void menu(runner_t *run)
{
    // if (run->count == 1) {
    //     sfRenderWindow_clear(run->window, sfBlack);
    //     sfRenderWindow_drawSprite(run->window, run->bg, NULL);
    //     sfRenderWindow_drawSprite(run->window, run->pill, NULL);
    //     sfRenderWindow_drawSprite(run->window, run->fg, NULL);
    //     sfRenderWindow_drawSprite(run->window, run->player, NULL);
    //     sfRenderWindow_drawSprite(run->window, run->ennemy, NULL);
    //     sfRenderWindow_drawSprite(run->window, run->life3, NULL);
    //     sfRenderWindow_drawSprite(run->window, run->score, NULL);
    //     sfRenderWindow_drawSprite(run->window, run->score1, NULL);
    //     sfRenderWindow_drawSprite(run->window, run->score2, NULL);
    //     sfRenderWindow_drawSprite(run->window, run->score3, NULL);
    //     if (run->obs == 0)
    //         obstacle(run);
    //     collision(run);
    //     life(run);
    //     sfRenderWindow_drawSprite(run->window, run->mouse, NULL);
    // }
    menu2(run);
}

void menu2(runner_t *run)
{
    if (run->count == 0) {
        // button(run);
        sfRenderWindow_drawSprite(run->window, run->bg, NULL);
        // sfRenderWindow_drawSprite(run->window, run->menu, NULL);
        // sfRenderWindow_drawSprite(run->window, run->play, NULL);
        // sfRenderWindow_drawSprite(run->window, run->back, NULL);
        // sfRenderWindow_drawSprite(run->window, run->set, NULL);
        // sfRenderWindow_drawSprite(run->window, run->mouse, NULL);
    }
    if (run->count == 3) {
        // button2(run);
        sfRenderWindow_drawSprite(run->window, run->set2, NULL);
        sfRenderWindow_drawSprite(run->window, run->fps1, NULL);
        sfRenderWindow_drawSprite(run->window, run->fps2, NULL);
        sfRenderWindow_drawSprite(run->window, run->fps3, NULL);
        sfRenderWindow_drawSprite(run->window, run->dir, NULL);
        sfRenderWindow_drawSprite(run->window, run->mouse, NULL);
    }
    // menu3(run);
}

void menu3(runner_t *run)
{
    if (run->count == 4) {
        sfRenderWindow_drawSprite(run->window, run->win, NULL);
        sfRenderWindow_drawSprite(run->window, run->mouse, NULL);
    }
}