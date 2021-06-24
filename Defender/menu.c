/*
** EPITECH PROJECT, 2021
** menu
** File description:
** menu
*/

#include "include/my.h"
#include "include/struct.h"

void menu5(defender_t *defender)
{
    if (defender->count_menu == 0) {
        button(defender);
        button5(defender);
        sfRenderWindow_drawSprite(defender->window, defender->bg_menu, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->butt_play, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->butt_back, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->butt_sett, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->htp, NULL);
    }
}

void menu4(defender_t *defender)
{
    if (defender->second5 == 1) {
        sfMusic_play(defender->ts_sound5);
        sfRenderWindow_drawSprite(defender->window, defender->grass6, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->ts5, NULL);
    }
    if (defender->second6 == 1) {
        sfMusic_play(defender->ts_sound6);
        sfRenderWindow_drawSprite(defender->window, defender->grass5, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->ts6, NULL);
    }
    if (defender->second7 == 1) {
        sfMusic_play(defender->ts_sound7);
        sfRenderWindow_drawSprite(defender->window, defender->grass7, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->ts7, NULL);
    } sfRenderWindow_drawSprite(defender->window, defender->enemy, NULL);
    if (defender->count_kill == 2 && defender->count_mj == 0) {
        defender->count_path2 = 0;
        defender->count_mj = 1;
    }
    if (defender->count_mj == 1)
        sfRenderWindow_drawSprite(defender->window, defender->mj, NULL);
    sfRenderWindow_drawSprite(defender->window, defender->vie1, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
        defender->count_menu = 3;
    button7(defender);
    build(defender);
}

void menu3(defender_t *defender)
{
    if (defender->second == 1) {
        sfRenderWindow_drawSprite(defender->window, defender->grass1, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->ts, NULL);
    }
    if (defender->second2 == 1) {
        sfMusic_play(defender->ts_sound2);
        sfRenderWindow_drawSprite(defender->window, defender->grass3, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->ts2, NULL);
    }
    if (defender->second3 == 1) {
        sfMusic_play(defender->ts_sound3);
        sfRenderWindow_drawSprite(defender->window, defender->grass4, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->ts3, NULL);
    }
    if (defender->second4 == 1) {
        sfMusic_play(defender->ts_sound4);
        sfRenderWindow_drawSprite(defender->window, defender->grass2, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->ts4, NULL);
    }
}

void menu(defender_t *defender)
{
    menu5(defender);
    if (defender->count_menu == 1) {
        menu6(defender);
        check_hit9(defender, defender->pos_shot2, defender->pos_mj,
        defender->first2);
        check_hit10(defender, defender->pos_shot3, defender->pos_mj,
        defender->first3);
        check_hit11(defender, defender->pos_shot4, defender->pos_mj,
        defender->first4);
        check_hit12(defender, defender->pos_shot5, defender->pos_mj,
        defender->first5);
        check_hit13(defender, defender->pos_shot6, defender->pos_mj,
        defender->first6);
        check_hit14(defender, defender->pos_shot7, defender->pos_mj,
        defender->first7);
        menu7(defender);
        menu8(defender);
    }
    menu2(defender);
}

void menu2(defender_t *defender)
{
    if (defender->count_menu == 2) {
        button2(defender);
        sfRenderWindow_drawSprite(defender->window, defender->bg_sett, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->arrow, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->butt_60, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->butt_120, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->butt_180, NULL);
    }
    if (defender->count_menu == 3) {
        paus(defender);
    }
    if (defender->count_menu == 4) {
        button6(defender);
        sfRenderWindow_drawSprite(defender->window, defender->m_htp, NULL);
        sfRenderWindow_drawSprite(defender->window, defender->arrow, NULL);
    }
    win_cond(defender);
}