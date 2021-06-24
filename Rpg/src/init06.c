/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void init_life_bars2(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->life_sard_jason_spr,
    rpg->life_bar_text, sfTrue);
    sfSprite_setTexture(rpg->life_jason_spr, rpg->life_bar_text, sfTrue);
    rpg->life_sard_jason_rec = (sfIntRect) {0, 0, 0, 18};
    rpg->life_jason_rect = (sfIntRect) {0, 0, 0, 18};
    sfSprite_setTextureRect(rpg->life_jason_spr,
    rpg->life_jason_rect);
    sfSprite_setTextureRect(rpg->life_sard_jason_spr,
    rpg->life_sard_jason_rec);
    rpg->life_sard_rock_spr = sfSprite_create();
    rpg->life_rock_spr = sfSprite_create();
    sfSprite_setTexture(rpg->life_sard_rock_spr,
    rpg->life_bar_text, sfTrue);
    sfSprite_setTexture(rpg->life_rock_spr, rpg->life_bar_text, sfTrue);
    rpg->life_sard_rock_rect = (sfIntRect) {0, 0, 0, 18};
    rpg->life_rock_rect = (sfIntRect) {0, 0, 0, 18};
    sfSprite_setTextureRect(rpg->life_rock_spr, rpg->life_rock_rect);
    sfSprite_setTextureRect(rpg->life_sard_rock_spr,
    rpg->life_sard_rock_rect);
}

void init_cut_scene(rpg_t *rpg)
{
    rpg->cut_scene_spr = sfSprite_create();
    rpg->cut_scene_text = sfTexture_createFromFile("assets/cut_scene.png",
    NULL);
    sfSprite_setTexture(rpg->cut_scene_spr, rpg->cut_scene_text, sfTrue);
}

void init_download_cut_scene(rpg_t *rpg)
{
    char *str = "assets/download_bar.png";
    rpg->download_cut_scene_text = sfTexture_createFromFile(str, NULL);
    rpg->download_cut_scene_spr = sfSprite_create();
    sfSprite_setPosition(rpg->download_cut_scene_spr, (sfVector2f) {315, 820});
    sfSprite_setTexture(rpg->download_cut_scene_spr,
    rpg->download_cut_scene_text, sfTrue);
    rpg->download_cut_scene_rect = (sfIntRect) {0, 0, 0, 116};
    sfSprite_setTextureRect(rpg->download_cut_scene_spr,
    rpg->download_cut_scene_rect);
}