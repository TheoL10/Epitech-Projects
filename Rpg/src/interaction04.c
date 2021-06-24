/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void interaction_with_lorenzo_quest(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        lorenzo_quest1(rpg);
        lorenzo_quest2(rpg);
        lorenzo_quest3(rpg);
        lorenzo_quest4(rpg);
        lorenzo_quest5(rpg);
        lorenzo_quest6(rpg);
        lorenzo_quest7(rpg);
    }
}

void lorenzo_quest1(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '2'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '2')
    && rpg->step_of_game == 1) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[48]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[49]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[50]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[51]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[3]);
    }
}

void lorenzo_quest2(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyE
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == '2'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == '2'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == '2')
    && rpg->step_of_game == 2) {
        rpg->speech = 1;
        sfText_setString(rpg->speech_txt1, rpg->dialog[53]);
        sfText_setString(rpg->speech_txt2, rpg->dialog[54]);
        sfText_setString(rpg->speech_txt3, rpg->dialog[55]);
        sfText_setString(rpg->speech_txt4, rpg->dialog[56]);
        sfText_setString(rpg->name_pnj_txt, rpg->name[3]);
    }
}

void interaction_with_useless_pnj(rpg_t *rpg, int wich_name)
{
    sfText_setString(rpg->speech_txt1, rpg->dialog[42]);
    sfText_setString(rpg->speech_txt2, rpg->dialog[43]);
    sfText_setString(rpg->speech_txt3, rpg->dialog[44]);
    sfText_setString(rpg->speech_txt4, rpg->dialog[45]);
    sfText_setString(rpg->name_pnj_txt, rpg->name[wich_name]);
}

void interaction_with_the_rock(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)
    && (rpg->map[rpg->y_character + 1][rpg->x_character] == 'c'
    || rpg->map[rpg->y_character - 1][rpg->x_character] == 'c'
    || rpg->map[rpg->y_character][rpg->x_character + 1] == 'c'
    || rpg->map[rpg->y_character][rpg->x_character - 1] == 'c')) {
        rpg->main_menu = 6;
    }
}