/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"

void my_putchar(int c);
int my_putstr(char const *str);
void sprite(runner_t *run);
void sprite2(runner_t *run);
void texture(runner_t *run);
void texture2(runner_t *run);
void set_texture(runner_t *run);
void set_texture2(runner_t *run);
void animation(runner_t *run);
void animation_jump(runner_t *run);
void position(runner_t *run);
void position2(runner_t *run);
void menu(runner_t *run);
void menu2(runner_t *run);
void menu3(runner_t *run);
void button(runner_t *run);
void button2(runner_t *run);
void button3(runner_t *run);
void init_score(runner_t *run);
void score(runner_t *run);
void score2(runner_t *run);
void score3(runner_t *run);
void call(runner_t *run);
void parallax(runner_t *run);
void description(void);
void game_loop(runner_t *run);
void rectangle(runner_t *run);
void setscale(runner_t *run);
void clock(runner_t *run);
void setposition(runner_t *run);
int jump(runner_t *run);
void readmap(runner_t *run, char **argv);
void obstacle(runner_t *run);
void kill(runner_t *run);
void collision(runner_t *run);
void life(runner_t *run);

#endif
