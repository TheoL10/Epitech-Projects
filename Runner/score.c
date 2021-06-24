/*
** EPITECH PROJECT, 2021
** score
** File description:
** score
*/

#include "include/my.h"
#include "include/struct.h"

void init_score(runner_t *run)
{
    run->time_score1 = sfClock_getElapsedTime(run->clock_score1);
    run->time_score2 = sfClock_getElapsedTime(run->clock_score2);
    run->time_score3 = sfClock_getElapsedTime(run->clock_score3);
    run->float_score1 = run->time_score1.microseconds / 1000000.0;
    run->float_score2 = run->time_score2.microseconds / 1000000.0;
    run->float_score3 = run->time_score3.microseconds / 1000000.0;
    score(run);
}

void score(runner_t *run)
{
    if (run->float_score1 > 0.1 &&  run->count == 1) {
        run->rect_score1.left += 75;
        if (run->rect_score1.left >= 684) {
            run->rect_score1.left = 0;
            run->scr = 1;
            run->scr2++;
        }
        sfClock_restart(run->clock_score1);
        sfSprite_setPosition(run->score1, run->pos_score1);
        sfSprite_setPosition(run->score2, run->pos_score2);
        sfSprite_setPosition(run->score3, run->pos_score3);
        sfSprite_setTextureRect(run->score1, run->rect_score1);
        sfSprite_setTextureRect(run->score2, run->rect_score2);
        sfSprite_setTextureRect(run->score3, run->rect_score3);
    }
    score2(run);
    score3(run);
}

void score2(runner_t *run)
{
    if (run->float_score2 > 0.8 && run->scr == 1 && run->count == 1) {
        run->rect_score2.left += 75;
        if (run->rect_score2.left >= 684) {
            run->rect_score2.left = 75 * run->scr2;
            run->rect_score2.left = 0;
            run->scr = 2;
            run->scr3++;
        }
        sfClock_restart(run->clock_score2);
        sfSprite_setTextureRect(run->score2, run->rect_score2);
    }
}

void score3(runner_t *run)
{
    if (run->float_score3 > 0.8 && run->scr == 2 && run->count == 1) {
        run->rect_score3.left += 75;
        run->scr = 3;
        if (run->rect_score3.left >= 684) {
            run->rect_score3.left = 75 * run->scr3;
            run->rect_score3.left = 0;
            run->scr = 0;
        }
        sfClock_restart(run->clock_score3);
        sfSprite_setTextureRect(run->score3, run->rect_score3);
    }
    if (run->rect_score1.left == 675 && run->rect_score2.left == 675
    && run->rect_score3.left == 675)
        run->count = 4;
}