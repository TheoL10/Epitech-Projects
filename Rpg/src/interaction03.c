/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void interaction_with_lafouine(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        if (rpg->event.key.code == sfKeyE
        && (rpg->map[rpg->y_character + 1][rpg->x_character] == '6'
        || rpg->map[rpg->y_character - 1][rpg->x_character] == '6'
        || rpg->map[rpg->y_character][rpg->x_character + 1] == '6'
        || rpg->map[rpg->y_character][rpg->x_character - 1] == '-')
        && rpg->step_of_game != 4) {
            rpg->speech = 1;
            interaction_with_useless_pnj(rpg, 7);
        }
        interaction_with_lafouine2(rpg);
    }
}

void interaction_with_lafouine2(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
        && (rpg->map[rpg->y_character + 1][rpg->x_character] == '6'
        || rpg->map[rpg->y_character - 1][rpg->x_character] == '6'
        || rpg->map[rpg->y_character][rpg->x_character + 1] == '6'
        || rpg->map[rpg->y_character][rpg->x_character - 1] == '6')
        && rpg->step_of_game == 4) {
            rpg->speech = 1;
            sfText_setString(rpg->speech_txt1, rpg->dialog[27]);
            sfText_setString(rpg->speech_txt2, rpg->dialog[28]);
            sfText_setString(rpg->speech_txt3, rpg->dialog[29]);
            sfText_setString(rpg->speech_txt4, rpg->dialog[30]);
            sfText_setString(rpg->name_pnj_txt, rpg->name[7]);
            rpg->step_of_game = 5;
        }
}

void interaction_with_alkapote(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '7'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '7'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '7'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '7')) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[37]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[38]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[39]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[40]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[8]);
    }
}

void interaction_with_alderiate(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == 'a'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == 'a'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == 'a'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == 'a')) {
        rpg->main_menu = 4;
    }
}

void interaction_with_jason(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == 'b'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == 'b'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == 'b'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == 'b')) {
        rpg->main_menu = 5;
    }
}