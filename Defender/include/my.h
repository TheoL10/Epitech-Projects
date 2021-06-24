/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"
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

void my_putchar(int c);
int my_putstr(char const *str);
void sprite(defender_t *defender);
void sprite2(defender_t *defender);
void sprite3(defender_t *defender);
void sprite4(defender_t *defender);
void sprite5(defender_t *defender);
void texture(defender_t *defender);
void texture2(defender_t *defender);
void texture3(defender_t *defender);
void texture4(defender_t *defender);
void texture5(defender_t *defender);
void set_texture(defender_t *defender);
void set_texture2(defender_t *defender);
void set_texture4(defender_t *defender);
void set_texture6(defender_t *defender);
void set_position(defender_t *defender);
void set_position2(defender_t *defender);
void set_position5(defender_t *defender);
void position(defender_t *defender);
void position2(defender_t *defender);
void position3(defender_t *defender);
void position4(defender_t *defender);
void position7(defender_t *defender);
void position8(defender_t *defender);
void game_loop(defender_t *defender);
void call2(defender_t *defender);
void menu(defender_t *defender);
void menu2(defender_t *defender);
void menu3(defender_t *defender);
void menu4(defender_t *defender);
void menu5(defender_t *defender);
void menu6(defender_t *defender);
void menu7(defender_t *defender);
void menu8(defender_t *defender);
void button(defender_t *defender);
void button2(defender_t *defender);
void button3(defender_t *defender);
void button4(defender_t *defender);
void button5(defender_t *defender);
void button6(defender_t *defender);
void button7(defender_t *defender);
void button8(defender_t *defender);
void button9(defender_t *defender);
void button10(defender_t *defender);
void build(defender_t *defender);
void build(defender_t *defender);
void tower(defender_t *defender);
void tower2(defender_t *defender);
void tower3(defender_t *defender);
void tower4(defender_t *defender);
void tower5(defender_t *defender);
void tower6(defender_t *defender);
void tower7(defender_t *defender);
void tower8(defender_t *defender);
void tower9(defender_t *defender);
void tower10(defender_t *defender);
void tower11(defender_t *defender);
void tower12(defender_t *defender);
void tower13(defender_t *defender);
void tower14(defender_t *defender);
void tower15(defender_t *defender);
void tower16(defender_t *defender);
void tower17(defender_t *defender);
void tower18(defender_t *defender);
void tower19(defender_t *defender);
void tower20(defender_t *defender);
void tower21(defender_t *defender);
void tower22(defender_t *defender);
void tower23(defender_t *defender);
void tower24(defender_t *defender);
void tower25(defender_t *defender);
void tower26(defender_t *defender);
void tower27(defender_t *defender);
void tower28(defender_t *defender);
void call_path5(defender_t *defender);
void call_path6(defender_t *defender);
void call_path7(defender_t *defender);
void call_path8(defender_t *defender);
void call_path4(defender_t *defender);
void call_path3(defender_t *defender);
void call_path2(defender_t *defender);
void call_path1(defender_t *defender);
void enemy_path(defender_t *defender);
char *my_getnbrinverse(int tmp, int k, int trans, int is_neg);
void paus(defender_t *defender);
void vie(defender_t *defender);
void call_sh4(defender_t *defender);
void call_sh3(defender_t *defender);
void call_sh2(defender_t *defender);
void call_sh1(defender_t *defender);
void call_shot5(defender_t *defender);
void call_shot6(defender_t *defender);
void call_shot7(defender_t *defender);
void call_shot8(defender_t *defender);
void rst_sh2(defender_t *defender);
void rst_sh1(defender_t *defender);
void set_texture3(defender_t *defender);
void call_shdir4(defender_t *defender);
void call_shdir3(defender_t *defender);
void call_shdir2(defender_t *defender);
void call_shdir1(defender_t *defender);
void set_position3(defender_t *defender);
void position6(defender_t *defender);
void position5(defender_t *defender);
void call_shot9(defender_t *defender);
void call_shot10(defender_t *defender);
void call_shot11(defender_t *defender);
void call_shot12(defender_t *defender);
void call_shot13(defender_t *defender);
void call_shot14(defender_t *defender);
void call_shot15(defender_t *defender);
void call_shot16(defender_t *defender);
void call_shot17(defender_t *defender);
void call_shot18(defender_t *defender);
void call_shot19(defender_t *defender);
void call_shot20(defender_t *defender);
void call_shot21(defender_t *defender);
void call_shot22(defender_t *defender);
void call_shot23(defender_t *defender);
void call_shot24(defender_t *defender);
void call_shot25(defender_t *defender);
void call_shot26(defender_t *defender);
void call_shot27(defender_t *defender);
void call_shot28(defender_t *defender);
void call_shdir5(defender_t *defender);
void call_shdir6(defender_t *defender);
void call_shdir7(defender_t *defender);
void call_shdir8(defender_t *defender);
void call_shdir9(defender_t *defender);
void call_shdir10(defender_t *defender);
void call_shdir11(defender_t *defender);
void call_shdir12(defender_t *defender);
void call_shdir13(defender_t *defender);
void call_shdir14(defender_t *defender);
void rst_sh3(defender_t *defender);
void rst_sh4(defender_t *defender);
void rst_sh5(defender_t *defender);
void rst_sh6(defender_t *defender);
void rst_sh7(defender_t *defender);
void enemy_shot(defender_t *defender);
void enemy_shot2(defender_t *defender);
void enemy_shot3(defender_t *defender);
void enemy_shot4(defender_t *defender);
void enemy_shot5(defender_t *defender);
void enemy_shot6(defender_t *defender);
void enemy_shot7(defender_t *defender);
void animation1(defender_t *defender);
void animation4(defender_t *defender);
void set_position4(defender_t *defender);
void set_texture5(defender_t *defender);
void animation3(defender_t *defender);
void animation2(defender_t *defender);
void draw_grass_second(defender_t *defender);
void second_clock(defender_t *defender);
void cond_third(defender_t *defender);
void set_texture_rect(defender_t *defender);
void music2(defender_t *defender);
void music(defender_t *defender);
void create_music_fromfile(defender_t *defender);
void enemy_shot8(defender_t *defender);
void enemy_shot9(defender_t *defender);
void enemy_shot10(defender_t *defender);
void enemy_shot11(defender_t *defender);
void enemy_shot12(defender_t *defender);
void enemy_shot13(defender_t *defender);
void enemy_shot14(defender_t *defender);
void enemy_shot15(defender_t *defender);
void check_hit(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit2(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit3(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit4(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit5(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit6(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit7(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit8(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit9(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit10(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit11(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit12(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit13(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
void check_hit14(defender_t *defender, sfVector2f pos_sprite1,
sfVector2f pos_sprite2, int zbi);
char *my_revstr(char *str);
void position10(defender_t *defender);
void win_cond(defender_t *defender);

#endif