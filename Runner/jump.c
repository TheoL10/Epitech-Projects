/*
** EPITECH PROJECT, 2020
** jump
** File description:
** jump
*/

#include "include/my.h"
#include "include/struct.h"

int jump(runner_t *run)
{
    int count2 = 0;

    if (count2 == 2) {
        run->rect_animation.left += 157;
        count2 = 0;
    }
    if (run->jump >= 13)
        run->pos_player.y += 20 * run->slow;
    if (run->jump < 10)
        run->pos_player.y -= 20 * run->slow;
    if (run->jump > 20) {
        run->count_jump = 0;
        run->jump = 0;
        run->slow = 1;
        sfMusic_stop(run->jumping);
    }
    return (0);
}