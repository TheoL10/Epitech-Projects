/*
** EPITECH PROJECT, 2020
** obstacle
** File description:
** obstacle
*/

#include "include/my.h"
#include "include/struct.h"

void obstacle(runner_t *run)
{
    if (run->nbx > 0)
        run->pos_ennemy.x -= (3 * run->speed);
    if (run->pos_ennemy.x <= -100 && run->obs2 != run->nbx) {
        sfMusic_stop(run->oof);
        run->pos_ennemy.x = 2000;
        run->coll = 0;
        run->obs2++;
        run->speed += 0.4;
    }
    if (run->pos_ennemy.x <= -100)
        run->vic++;
    sfSprite_setPosition(run->ennemy, run->pos_ennemy);
    sfRenderWindow_drawSprite(run->window, run->ennemy, NULL);
}

void collision(runner_t *run)
{
    if ((run->pos_ennemy.x - run->pos_player.x) < 142
    && (run->pos_ennemy.x - run->pos_player.x) > -37
    && run->pos_player.y > 670 && run->coll == 0
    && run->vie < 3) {
        run->vie++;
        run->coll = 1;
        sfMusic_play(run->oof);
    }
}

void life(runner_t *run)
{
    if (run->vie == 1)
        sfRenderWindow_drawSprite(run->window, run->life2, NULL);
    if (run->vie == 2)
        sfRenderWindow_drawSprite(run->window, run->life1, NULL);
    if (run->vie == 3) {
        sfRenderWindow_clear(run->window, sfBlack);
        sfRenderWindow_drawSprite(run->window, run->end, NULL);
    }
    if (run->vic == run->nbx && run->vie < 3) {
        run->count = 4;
    }
}