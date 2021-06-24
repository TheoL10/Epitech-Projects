/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void lorenzo_quest3(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '2'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '2')
    && rpg->step_of_game == 3) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[58]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[59]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[60]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[61]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[3]);
    }
}

void lorenzo_quest4(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '2'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '2')
    && rpg->step_of_game == 4) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[63]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[64]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[65]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[66]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[3]);
    }
}

void lorenzo_quest5(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '2'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '2')
    && rpg->step_of_game == 5) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[68]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[69]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[70]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[71]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[3]);
    }
}

void lorenzo_quest6(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '2'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '2')
    && rpg->step_of_game == 6) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[73]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[74]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[75]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[76]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[3]);
    }
}

void lorenzo_quest7(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '2'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '2')
    && rpg->step_of_game == 7) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[78]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[79]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[80]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[81]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[3]);
    }
}