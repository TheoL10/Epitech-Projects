/*
** EPITECH PROJECT, 2020
** creation
** File description:
** creation
*/

#include "include/my.h"
#include "include/struct.h"

void sprite(runner_t *run)
{
    run->bg = sfSprite_create();
    // run->pill = sfSprite_create();
    // run->fg = sfSprite_create();
    // run->player = sfSprite_create();
    // run->mouse = sfSprite_create();
    // run->menu = sfSprite_create();
    // run->play = sfSprite_create();
    // run->back = sfSprite_create();
    // run->ennemy = sfSprite_create();
    // run->life3 = sfSprite_create();
    // run->life2 = sfSprite_create();
    // run->life1 = sfSprite_create();
    // run->end = sfSprite_create();
    // run->set = sfSprite_create();
    // run->set2 = sfSprite_create();
    // run->jumping = sfMusic_createFromFile("ressources/jump.ogg");
    // run->oof = sfMusic_createFromFile("ressources/oof.ogg");
    // run->mine = sfMusic_createFromFile("ressources/mine.ogg");
    // sprite2(run);
}

void texture(runner_t *run)
{
    run->text_bg = sfTexture_createFromFile("ressources/bg.png", NULL);
    // run->text_pill = sfTexture_createFromFile("ressources/pill.png", NULL);
    // run->text_fg = sfTexture_createFromFile("ressources/fg.png", NULL);
    // run->text_player = sfTexture_createFromFile("ressources/player.png", NULL);
    // run->text_mouse = sfTexture_createFromFile("ressources/cursor.png", NULL);
    // run->text_menu = sfTexture_createFromFile("ressources/menu.png", NULL);
    // run->text_play = sfTexture_createFromFile("ressources/play.png", NULL);
    // run->text_back = sfTexture_createFromFile("ressources/back.png", NULL);
    // run->text_ennemy = sfTexture_createFromFile("ressources/ennemy.png", NULL);
    // run->text_life3 = sfTexture_createFromFile("ressources/vie3.png", NULL);
    // run->text_life2 = sfTexture_createFromFile("ressources/vie2.png", NULL);
    // run->text_life1 = sfTexture_createFromFile("ressources/vie1.png", NULL);
    // run->text_end = sfTexture_createFromFile("ressources/end.png", NULL);
    // run->text_set = sfTexture_createFromFile("ressources/b.png", NULL);
    // run->text_set2 = sfTexture_createFromFile("ressources/set.png", NULL);
    // run->text_fps1 = sfTexture_createFromFile("ressources/60.png", NULL);
    // run->text_fps2 = sfTexture_createFromFile("ressources/12.png", NULL);
    // run->text_fps3 = sfTexture_createFromFile("ressources/18.png", NULL);
    // texture2(run);
}

void set_texture(runner_t *run)
{
    sfSprite_setTexture(run->bg, run->text_bg, sfTrue);
    // sfSprite_setTexture(run->pill, run->text_pill, sfTrue);
    // sfSprite_setTexture(run->fg, run->text_fg, sfTrue);
    // sfSprite_setTexture(run->player, run->text_player, sfTrue);
    // sfSprite_setTexture(run->mouse, run->text_mouse, sfTrue);
    // sfSprite_setTexture(run->menu, run->text_menu, sfTrue);
    // sfSprite_setTexture(run->play, run->text_play, sfTrue);
    // sfSprite_setTexture(run->back, run->text_back, sfTrue);
    // sfSprite_setTexture(run->ennemy, run->text_ennemy, sfTrue);
    // sfSprite_setTexture(run->life3, run->text_life3, sfTrue);
    // sfSprite_setTexture(run->life2, run->text_life2, sfTrue);
    // sfSprite_setTexture(run->life1, run->text_life1, sfTrue);
    // sfSprite_setTexture(run->end, run->text_end, sfTrue);
    // sfSprite_setTexture(run->set, run->text_set, sfTrue);
    // sfSprite_setTexture(run->set2, run->text_set2, sfTrue);
    // sfSprite_setTexture(run->fps1, run->text_fps1, sfTrue);
    // sfSprite_setTexture(run->fps2, run->text_fps2, sfTrue);
    // sfSprite_setTexture(run->fps3, run->text_fps3, sfTrue);
    // set_texture2(run);
}

void clock(runner_t *run)
{
    run->move = sfClock_create();
    run->clock_animation = sfClock_create();
    run->clock_ennemy = sfClock_create();
    run->clock_score1 = sfClock_create();
    run->clock_score2 = sfClock_create();
    run->clock_score3 = sfClock_create();
}