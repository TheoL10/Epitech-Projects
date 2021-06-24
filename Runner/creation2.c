/*
** EPITECH PROJECT, 2021
** creation2
** File description:
** creation2
*/

#include "include/my.h"
#include "include/struct.h"

void sprite2(runner_t *run)
{
    run->fps1 = sfSprite_create();
    run->fps2 = sfSprite_create();
    run->fps3 = sfSprite_create();
    run->dir = sfSprite_create();
    run->win = sfSprite_create();
    run->score = sfSprite_create();
    run->score1 = sfSprite_create();
    run->score2 = sfSprite_create();
    run->score3 = sfSprite_create();
}

void texture2(runner_t *run)
{
    run->text_dir = sfTexture_createFromFile("ressources/flech.png", NULL);
    run->text_win = sfTexture_createFromFile("ressources/win.png", NULL);
    run->text_score = sfTexture_createFromFile("ressources/score.png", NULL);
    run->text_score1 = sfTexture_createFromFile("ressources/score1.png", NULL);
    run->text_score2 = sfTexture_createFromFile("ressources/score2.png", NULL);
    run->text_score3 = sfTexture_createFromFile("ressources/score2.png", NULL);
}

void set_texture2(runner_t *run)
{
    sfSprite_setTexture(run->dir, run->text_dir, sfTrue);
    sfSprite_setTexture(run->win, run->text_win, sfTrue);
    sfSprite_setTexture(run->score, run->text_score, sfTrue);
    sfSprite_setTexture(run->score1, run->text_score1, sfTrue);
    sfSprite_setTexture(run->score2, run->text_score2, sfTrue);
    sfSprite_setTexture(run->score3, run->text_score3, sfTrue);
}