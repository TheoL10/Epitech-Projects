/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void display_speech(rpg_t *rpg)
{
    if (rpg->speech >= 1) {
        rpg->coord_view = rpg->view;
        rpg->speech_vect = (sfVector2f)
        {(rpg->coord_view[0] - 960), (rpg->coord_view[1] - 540)};
        sfSprite_setPosition(rpg->speech_spr, rpg->speech_vect);
        sfRenderWindow_drawSprite(rpg->window, rpg->speech_spr, NULL);
        set_coord_speech(rpg);
        sfRenderWindow_drawText(rpg->window, rpg->speech_txt1, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->speech_txt2, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->name_pnj_txt, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->speech_txt3, NULL);
        sfRenderWindow_drawText(rpg->window, rpg->speech_txt4, NULL);
    }
}

void set_coord_speech(rpg_t *rpg)
{
    sfText_setPosition(rpg->speech_txt1, (sfVector2f)
    {(rpg->coord_view[0] - 940), (rpg->coord_view[1] + 300)});
    sfText_setPosition(rpg->speech_txt2, (sfVector2f)
    {(rpg->coord_view[0] - 940), (rpg->coord_view[1] + 355)});
    sfText_setPosition(rpg->speech_txt3, (sfVector2f)
    {(rpg->coord_view[0] - 940), (rpg->coord_view[1] + 410)});
    sfText_setPosition(rpg->speech_txt4, (sfVector2f)
    {(rpg->coord_view[0] - 940), (rpg->coord_view[1] + 465)});
    sfText_setPosition(rpg->name_pnj_txt, (sfVector2f)
    {(rpg->coord_view[0] - 870), (rpg->coord_view[1] + 215)});
}

void display_cut_scene(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window, rpg->cut_scene_spr, NULL);
    sfSprite_setTextureRect(rpg->download_cut_scene_spr,
    rpg->download_cut_scene_rect);
    sfRenderWindow_drawSprite(rpg->window, rpg->download_cut_scene_spr, NULL);
}