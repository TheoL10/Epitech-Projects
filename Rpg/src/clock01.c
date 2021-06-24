/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void dialog_clock(rpg_t *rpg)
{
    rpg->dialog_time = sfClock_getElapsedTime(rpg->dialog_clock);
    rpg->dialog_seconds = rpg->dialog_time.microseconds / 1000000.0;
    if (rpg->speech == 1) {
        sfClock_restart(rpg->dialog_clock);
        rpg->speech++;
    }
    rpg->dialog_time = sfClock_getElapsedTime(rpg->dialog_clock);
    rpg->dialog_seconds = rpg->dialog_time.microseconds / 1000000.0;
    if (rpg->speech > 1) {
        if (rpg->dialog_seconds > 10) {
            rpg->speech = 0;
            sfClock_restart(rpg->dialog_clock);
        }
    }
}

void download_cut_scene_clock(rpg_t *rpg)
{
    rpg->cutscene_time = sfClock_getElapsedTime(rpg->download_cut_scene_clock);
    rpg->cutscene_seconds = rpg->cutscene_time.microseconds / 1000000.0;
    if (rpg->cutscene_seconds > 0.05
    && rpg->download_cut_scene_rect.width != 1290) {
        rpg->download_cut_scene_rect.width += 1;
        sfClock_restart(rpg->dialog_clock);
    }
}