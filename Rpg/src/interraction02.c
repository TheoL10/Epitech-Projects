/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void interaction_with_lorenzo(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        if (rpg->event.key.code == sfKeyE
        && (rpg->map[rpg->y_character + 1][rpg->x_character] == '2'
        || rpg->map[rpg->y_character - 1][rpg->x_character] == '2'
        || rpg->map[rpg->y_character][rpg->x_character + 1] == '2'
        || rpg->map[rpg->y_character][rpg->x_character - 1] == '2')
        && rpg->step_of_game == 0) {
            rpg->speech = 1;
            sfText_setString(rpg->speech_txt1, rpg->dialog[2]);
            sfText_setString(rpg->speech_txt2, rpg->dialog[3]);
            sfText_setString(rpg->speech_txt3, rpg->dialog[4]);
            sfText_setString(rpg->speech_txt4, rpg->dialog[5]);
            sfText_setString(rpg->name_pnj_txt, rpg->name[3]);
            rpg->step_of_game = 1;
        }
    }
}

void interaction_with_roi_hennok_one(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        if (rpg->event.key.code == sfKeyE
        && (rpg->map[rpg->y_character + 1][rpg->x_character] == '3'
        || rpg->map[rpg->y_character - 1][rpg->x_character] == '3'
        || rpg->map[rpg->y_character][rpg->x_character + 1] == '3'
        || rpg->map[rpg->y_character][rpg->x_character - 1] == '3')
        && rpg->step_of_game != 1) {
            rpg->speech = 1;
            interaction_with_useless_pnj(rpg, 4);
        }
        interaction_with_roi_hennok_one2(rpg);
    }
}

void interaction_with_roi_hennok_one2(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
        && (rpg->map[rpg->y_character + 1][rpg->x_character] == '3'
        || rpg->map[rpg->y_character - 1][rpg->x_character] == '3'
        || rpg->map[rpg->y_character][rpg->x_character + 1] == '3'
        || rpg->map[rpg->y_character][rpg->x_character - 1] == '3')
        && rpg->step_of_game == 1) {
            rpg->speech = 1;
            sfText_setString(rpg->speech_txt1, rpg->dialog[7]);
            sfText_setString(rpg->speech_txt2, rpg->dialog[8]);
            sfText_setString(rpg->speech_txt3, rpg->dialog[9]);
            sfText_setString(rpg->speech_txt4, rpg->dialog[10]);
            sfText_setString(rpg->name_pnj_txt, rpg->name[4]);
            rpg->step_of_game = 2;
        }
}

void interaction_with_booba(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        if (rpg->event.key.code == sfKeyE
        && (rpg->map[rpg->y_character + 1][rpg->x_character] == '4'
        || rpg->map[rpg->y_character - 1][rpg->x_character] == '4'
        || rpg->map[rpg->y_character][rpg->x_character + 1] == '4'
        || rpg->map[rpg->y_character][rpg->x_character - 1] == '4')
        && rpg->step_of_game != 2) {
            rpg->speech = 1;
            interaction_with_useless_pnj(rpg, 5);
        }
        interaction_with_booba2(rpg);
    }
}

void interaction_with_booba2(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
        && (rpg->map[rpg->y_character + 1][rpg->x_character] == '4'
        || rpg->map[rpg->y_character - 1][rpg->x_character] == '4'
        || rpg->map[rpg->y_character][rpg->x_character + 1] == '4'
        || rpg->map[rpg->y_character][rpg->x_character - 1] == '4')
        && rpg->step_of_game == 2) {
            rpg->speech = 1;
            sfText_setString(rpg->speech_txt1, rpg->dialog[12]);
            sfText_setString(rpg->speech_txt2, rpg->dialog[13]);
            sfText_setString(rpg->speech_txt3, rpg->dialog[14]);
            sfText_setString(rpg->speech_txt4, rpg->dialog[15]);
            sfText_setString(rpg->name_pnj_txt, rpg->name[5]);
            rpg->step_of_game = 3;
        }
}