/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"

void sprite(hunter_t *hunter);
void texture(texture_hunter_t *hunter);
void set_texture(hunter_t *hunter, texture_hunter_t *text_hunter);
void game_loop(hunter_t *hunter, texture_hunter_t *text_hunter);
void kill_bird(hunter_t *hunter);
void button(hunter_t *hunter);
void button2(hunter_t *hunter);
void window_game(hunter_t *hunter);
void kill_game(hunter_t *hunter, texture_hunter_t *text_hunter);
void boom(hunter_t *hunter);
void move_sprite(hunter_t *hunter);
void animation(hunter_t *hunter);
int my_putstr(char const *str);
void audio(hunter_t *hunter);
void clock(hunter_t *hunter);
void my_putchar(int c);
int my_put_nbr(int nb);
void mouse_action(hunter_t *hunter);
void draw_sprite(hunter_t *hunter);
void draw_sprite2(hunter_t *hunter);
void menu(hunter_t *hunter);
void position(hunter_t *hunter);
void vie(hunter_t *hunter);
void set_position_menu1(hunter_t *hunter);
void set_position_menu2(hunter_t *hunter);
void miss_click(hunter_t *hunter);
void miss_click2(hunter_t *hunter);

#endif