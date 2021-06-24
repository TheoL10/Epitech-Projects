/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

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

typedef struct sprite_hunter_s
{
    sfEvent event;
    sfRenderWindow* window;
    sfSprite* sprite_fond;
    sfSprite* sprite_bird;
    sfSprite* sprite_mouse;
    sfSprite* sprite_bm;
    sfSprite* sprite_menu;
    sfSprite* sprite_butt_p;
    sfSprite* sprite_butt_b;
    sfSprite* sprite_butt_s;
    sfSprite* sprite_v3;
    sfSprite* sprite_v2;
    sfSprite* sprite_v1;
    sfSprite* sprite_bg;
    sfSprite* sprite_menu_s;
    sfSprite* sprite_butt_60;
    sfSprite* sprite_butt_12;
    sfSprite* sprite_butt_18;
    sfSprite* sprite_arrow;
    float seconds;
    float movefloat;
    int menu;
    int vie;
    int count;
    int life;
    float acceleration;
    sfTime time;
    sfTime movetime;
    sfIntRect bird;
    sfClock* clock;
    sfClock* move;
    sfVector2f pos;
    sfVector2f pos_boom;
    sfVector2f pos_butt_p;
    sfVector2f pos_butt_b;
    sfVector2f pos_butt_s;
    sfVector2f pos_v3;
    sfVector2f pos_v2;
    sfVector2f pos_v1;
    sfVector2f pos_butt_60;
    sfVector2f pos_butt_120;
    sfVector2f pos_butt_180;
    sfVector2f pos_text;
    sfVector2i ms;
    sfMusic* boom;
} hunter_t;


typedef struct texture_hunter_s
{
    sfTexture* text_fond;
    sfTexture* text_bird;
    sfTexture* text_mouse;
    sfTexture* text_boom;
    sfTexture* text_menu;
    sfTexture* text_but_p;
    sfTexture* text_but_b;
    sfTexture* text_but_s;
    sfTexture* text_v3;
    sfTexture* text_v2;
    sfTexture* text_v1;
    sfTexture* text_bg;
    sfTexture* text_men_s;
    sfTexture* text_b_60;
    sfTexture* text_b_2;
    sfTexture* text_b_8;
    sfTexture* text_arrow;
} texture_hunter_t;
#endif