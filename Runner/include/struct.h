/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "my.h"
#include<SFML/Graphics/RenderWindow.h>
#include<SFML/Graphics/Export.h>
#include<SFML/Graphics/Rect.h>
#include<SFML/Graphics/Types.h>
#include<SFML/Window/Types.h>
#include<SFML/System.h>
#include<SFML/System/InputStream.h>
#include<SFML/System/Vector2.h>
#include<SFML/System/Time.h>
#include<SFML/System/Clock.h>
#include<SFML/Graphics.h>
#include<stddef.h>
#include<SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct runner_s
{
    sfRenderWindow* window;
    sfSprite* bg;
    sfSprite* pill;
    sfSprite* fg;
    sfSprite* player;
    sfSprite* mouse;
    sfSprite* menu;
    sfSprite* play;
    sfSprite* back;
    sfSprite* ennemy;
    sfSprite* life3;
    sfSprite* life2;
    sfSprite* life1;
    sfSprite* end;
    sfSprite* set;
    sfSprite* set2;
    sfSprite* fps1;
    sfSprite* fps2;
    sfSprite* fps3;
    sfSprite* dir;
    sfSprite* win;
    sfSprite* score;
    sfSprite* score1;
    sfSprite* score2;
    sfSprite* score3;
    sfTexture* text_bg;
    sfTexture* text_pill;
    sfTexture* text_fg;
    sfTexture* text_player;
    sfTexture* text_mouse;
    sfTexture* text_menu;
    sfTexture* text_play;
    sfTexture* text_back;
    sfTexture* text_ennemy;
    sfTexture* text_life3;
    sfTexture* text_life2;
    sfTexture* text_life1;
    sfTexture* text_end;
    sfTexture* text_set;
    sfTexture* text_set2;
    sfTexture* text_fps1;
    sfTexture* text_fps2;
    sfTexture* text_fps3;
    sfTexture* text_dir;
    sfTexture* text_win;
    sfTexture* text_score;
    sfTexture* text_score1;
    sfTexture* text_score2;
    sfTexture* text_score3;
    int count;
    char *buf;
    int o;
    int size;
    int file;
    int move_ennemy;
    int count_obs;
    int count_jump;
    int jump;
    int count2;
    int obs;
    int nbx;
    int music;
    int obs2;
    int vie;
    int coll;
    int vic;
    int scr;
    int scr2;
    int scr3;
    sfEvent event;
    sfClock* move;
    sfClock* clock_animation;
    sfClock* clock_ennemy;
    sfClock* clock_score1;
    sfClock* clock_score2;
    sfClock* clock_score3;
    sfTime para;
    sfTime time_animation;
    sfTime time_ennemy;
    sfTime time_score1;
    sfTime time_score2;
    sfTime time_score3;
    float float_para;
    float float_animation;
    float float_ennemy;
    float slow;
    float float_score1;
    float float_score2;
    float float_score3;
    float speed;
    sfIntRect rect_para;
    sfIntRect rect_para2;
    sfIntRect rect_para3;
    sfIntRect rect_animation;
    sfIntRect rect_score1;
    sfIntRect rect_score2;
    sfIntRect rect_score3;
    sfVector2f pos_para2;
    sfVector2f pos_player;
    sfVector2f pos_play;
    sfVector2f pos_back;
    sfVector2f pos_ennemy;
    sfVector2f pos_life3;
    sfVector2f pos_life2;
    sfVector2f pos_life1;
    sfVector2f pos_set;
    sfVector2f pos_fps1;
    sfVector2f pos_fps2;
    sfVector2f pos_fps3;
    sfVector2f pos_dir;
    sfVector2f pos_score1;
    sfVector2f pos_score2;
    sfVector2f pos_score3;
    sfVector2i pos_mouse;
    sfMusic* jumping;
    sfMusic* oof;
    sfMusic* mine;
} runner_t;


#endif
