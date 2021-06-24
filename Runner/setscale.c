/*
** EPITECH PROJECT, 2020
** setscale
** File description:
** setscale
*/

#include "include/my.h"
#include "include/struct.h"

void setscale(runner_t *run)
{
    sfSprite_setScale(run->pill, (sfVector2f) {1, 1.1});
    sfSprite_setScale(run->player, (sfVector2f) {1.5, 1.5});
    sfSprite_setScale(run->mouse, (sfVector2f) {0.1, 0.1});
    sfSprite_setScale(run->ennemy, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(run->life3, (sfVector2f) {0.6, 0.6});
    sfSprite_setScale(run->life2, (sfVector2f) {0.6, 0.6});
    sfSprite_setScale(run->life1, (sfVector2f) {0.6, 0.6});
    sfSprite_setScale(run->score, (sfVector2f) {0.8, 0.6});
    sfSprite_setScale(run->score1, (sfVector2f) {0.8, 0.8});
    sfSprite_setScale(run->score2, (sfVector2f) {0.8, 0.8});
    sfSprite_setScale(run->score3, (sfVector2f) {0.8, 0.8});
}