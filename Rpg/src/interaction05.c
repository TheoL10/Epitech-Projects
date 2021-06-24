/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void interaction_with_kaaris_non_nrv(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '5'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '5'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '5'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '5')
    && rpg->step_of_game == 3 && rpg->song_for_kaaris == 1) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[22]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[23]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[24]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[25]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[10]);
        rpg->step_of_game = 4;
    }
    interaction_with_kaaris_non_nrv2(rpg);
}

void interaction_with_kaaris_non_nrv2(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyF
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '5'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '5'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '5'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '5')
    && rpg->step_of_game == 3 && rpg->song_for_kaaris == 0) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[83]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[84]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[84]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[84]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[9]);
        rpg->song_for_kaaris = 1;
    }
}

void interaction_with_kaaris(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        if (rpg->event.key.code == sfKeyE
        && (rpg->map[rpg->y_character + 1][rpg->x_character] == '5'
        || rpg->map[rpg->y_character - 1][rpg->x_character] == '5'
        || rpg->map[rpg->y_character][rpg->x_character + 1] == '5'
        || rpg->map[rpg->y_character][rpg->x_character - 1] == '5')
        && rpg->step_of_game != 3 && rpg->song_for_kaaris == 1) {
            rpg->speech = 1;
            interaction_with_useless_pnj(rpg, 6);
        }
        interaction_with_kaaris_non_nrv(rpg);
        interaction_with_kaaris2(rpg);
    }
}

void interaction_with_kaaris2(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
        && (rpg->map[rpg->y_character + 1][rpg->x_character] == '5'
        || rpg->map[rpg->y_character - 1][rpg->x_character] == '5'
        || rpg->map[rpg->y_character][rpg->x_character + 1] == '5'
        || rpg->map[rpg->y_character][rpg->x_character - 1] == '5')
        && rpg->step_of_game == 3 && rpg->song_for_kaaris == 0) {
            rpg->speech = 1;
            sfText_setString(rpg->speech_txt1, rpg->dialog[17]);
            sfText_setString(rpg->speech_txt2, rpg->dialog[18]);
            sfText_setString(rpg->speech_txt3, rpg->dialog[19]);
            sfText_setString(rpg->speech_txt4, rpg->dialog[20]);
            sfText_setString(rpg->name_pnj_txt, rpg->name[6]);
        }
}

void interaction_for_the_end(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == 'z'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == 'z'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == 'z'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == 'z')
    && rpg->step_of_game == 8) {
        rpg->view = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
        sfRenderWindow_setView(rpg->window, rpg->view);
        rpg->main_menu = 8;
    }
}