/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void init_text_font(rpg_t *rpg)
{
    rpg->speech_font = sfFont_createFromFile("assets/font_dialog.ttf");
    rpg->speech_txt1 = sfText_create();
    rpg->speech_txt2 = sfText_create();
    rpg->speech_txt3 = sfText_create();
    rpg->speech_txt4 = sfText_create();
    rpg->name_pnj_txt = sfText_create();
    sfText_setFont(rpg->name_pnj_txt, rpg->speech_font);
    sfText_setColor(rpg->name_pnj_txt, sfBlack);
    sfText_setFont(rpg->speech_txt1, rpg->speech_font);
    sfText_setFont(rpg->speech_txt2, rpg->speech_font);
    sfText_setFont(rpg->speech_txt3, rpg->speech_font);
    sfText_setFont(rpg->speech_txt4, rpg->speech_font);
}

void init_music(rpg_t *rpg)
{
    rpg->music_fond = sfMusic_createFromFile("assets/musique_fond.ogg");
}

void init_life_bars(rpg_t *rpg)
{
    rpg->life_bar_text = sfTexture_createFromFile("assets/losing_hp.png", NULL);
    rpg->life_sard_alde_spr = sfSprite_create();
    rpg->life_alde_spr = sfSprite_create();
    sfSprite_setTexture(rpg->life_sard_alde_spr,
    rpg->life_bar_text, sfTrue);
    sfSprite_setTexture(rpg->life_alde_spr, rpg->life_bar_text, sfTrue);
    rpg->life_sard_alde_rect = (sfIntRect) {0, 0, 0, 18};
    rpg->life_alde_rect = (sfIntRect) {0, 0, 0, 18};
    sfSprite_setTextureRect(rpg->life_alde_spr, rpg->life_alde_rect);
    sfSprite_setTextureRect(rpg->life_sard_alde_spr,
    rpg->life_sard_alde_rect);
    rpg->life_sard_jason_spr = sfSprite_create();
    rpg->life_jason_spr = sfSprite_create();
    init_life_bars2(rpg);
}

void init_menu_combat_the_rock(rpg_t *rpg)
{
    rpg->coord_view = rpg->view;
    rpg->menu_c_the_rock_spr = sfSprite_create();
    rpg->menu_combat_the_rock_text =
    sfTexture_createFromFile("assets/menu_combat_the_rock.png", NULL);
    sfSprite_setTexture(rpg->menu_c_the_rock_spr,
    rpg->menu_combat_the_rock_text, sfTrue);
}