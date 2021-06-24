/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_runner
*/

#include "include/my.h"
#include "include/struct.h"

void parallax(runner_t *run)
{
    run->para = sfClock_getElapsedTime(run->move);
    run->float_para = run->para.microseconds / 120000.0;

    if (run->float_para >= 0.007) {
        run->rect_para.left += 3;
        run->rect_para2.left += 2;
        run->rect_para3.left += 1;
        if (run->rect_para.left > 1920)
            run->rect_para.left = 0;
        if (run->rect_para2.left > 1920)
            run->rect_para2.left = 0;
        if (run->rect_para3.left > 1920)
            run->rect_para3.left = 0;
        sfSprite_setPosition(run->pill, run->pos_para2);
        sfSprite_setTextureRect(run->fg, run->rect_para);
        sfSprite_setTextureRect(run->pill, run->rect_para2);
        sfSprite_setTextureRect(run->bg, run->rect_para3);
        sfClock_restart(run->move);
    }
}

void animation(runner_t *run)
{
    run->time_animation = sfClock_getElapsedTime(run->clock_animation);
    run->float_animation = run->time_animation.microseconds / 1000000.0;

    if (run->float_animation > 0.1) {
        run->rect_animation.left += 157;
        if (run->rect_animation.left >= 470)
            run->rect_animation.left = 0;
        sfClock_restart(run->clock_animation);
        sfSprite_setPosition(run->player, run->pos_player);
        sfSprite_setTextureRect(run->player, run->rect_animation);
    }
}

void animation_jump(runner_t *run)
{
    run->time_animation = sfClock_getElapsedTime(run->clock_animation);
    run->float_animation = run->time_animation.microseconds / 1000000.0;
    int count2 = 0;

    if (run->float_animation > 0.025) {
        run->slow = 1;
        run->jump++;
        run->slow -= 0.1;
        count2++;
        if (run->rect_animation.left >= 470)
            run->rect_animation.left = 0;
        sfClock_restart(run->clock_animation);
        sfSprite_setPosition(run->player, run->pos_player);
        sfSprite_setTextureRect(run->player, run->rect_animation);
        jump(run);
    }
}

void game_loop(runner_t *run)
{
    while (sfRenderWindow_isOpen(run->window)){
        while (sfRenderWindow_pollEvent(run->window, &run->event)) {
            if (run->event.type == sfEvtClosed)
                sfRenderWindow_close(run->window);
            // if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
            //     sfRenderWindow_close(run->window);
            // if (sfKeyboard_isKeyPressed(sfKeySpace) && run->count == 1) {
            //     run->count_jump = 1;
            //     sfMusic_play(run->jumping);
            // }
        }
        // sfRenderWindow_setMouseCursorVisible(run->window, sfFalse);
        // setposition(run);
        // init_score(run);
        // parallax(run);
        menu(run);
        sfRenderWindow_display(run->window);
    }
}