/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

int init_everything(rpg_t *rpg)
{
    rpg->map = open_file("assets/map.csv");
    if (rpg->map == NULL)
        return (84);
    rpg->dialog = open_file_dialog("assets/speech.txt");
    if (rpg->dialog == NULL)
        return (84);
    rpg->name = open_file_dialog("assets/name.txt");
    if (rpg->name == NULL)
        return (84);
    init_everything2(rpg);
    return (0);
}

void init_struct(rpg_t *rpg)
{
    rpg->main_menu = 1;
    rpg->step_of_game = 0;
}

void init_clock(rpg_t *rpg)
{
    rpg->character_clock = sfClock_create();
    rpg->dialog_clock = sfClock_create();
    rpg->download_cut_scene_clock = sfClock_create();
}

void init_character(rpg_t *rpg)
{
    rpg->character_spr = sfSprite_create();
    rpg->character_text = sfTexture_createFromFile("assets/character.png",
    NULL);
    sfSprite_setTexture(rpg->character_spr, rpg->character_text, sfTrue);
    rpg->character_rect = (sfIntRect) {0, 64, 64, 64};
    sfSprite_setTextureRect(rpg->character_spr, rpg->character_rect);
    rpg->character_vect = (sfVector2f) {3482, 461};
    sfSprite_setPosition(rpg->character_spr, rpg->character_vect);
}

void init_map(rpg_t *rpg)
{
    rpg->map_spr = sfSprite_create();
    rpg->map_text = sfTexture_createFromFile("assets/map.png", NULL);
    sfSprite_setTexture(rpg->map_spr, rpg->map_text, sfTrue);
    rpg->view = sfView_createFromRect((sfFloatRect)
    {(3482 - 902), (461 - 461), 1920, 1080});
}