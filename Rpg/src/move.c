/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo, GuillaumeH and GuillaumeP
*/

#include "../lib/my/my.h"

void move_view(rpg_t *rpg)
{
    detect_if_board(rpg);
    detect_collision(rpg);
    character_clock(rpg);
    if (rpg->walk_right == 1) {
        if (rpg->left_map == 0 && rpg->collision_right == 0)
            sfView_move(rpg->view, (sfVector2f) {8, 0});
        if (rpg->collision_right == 0)
            rpg->character_vect.x += 8;
        rpg->walk_right = 0;
        rpg->character_rect.top = 194;
    }
    if (rpg->walk_left == 1) {
        if (rpg->left_map == 0 && rpg->collision_left == 0)
            sfView_move(rpg->view, (sfVector2f) {-8, 0});
        if (rpg->collision_left == 0)
            rpg->character_vect.x -= 8;
        rpg->walk_left = 0;
        rpg->character_rect.top = 128;
    }
    move_view2(rpg);
}

void move_view2(rpg_t *rpg)
{
    if (rpg->walk_toward == 1) {
        if (rpg->top_map == 0 && rpg->collision_top == 0)
            sfView_move(rpg->view, (sfVector2f) {0, -8});
        if (rpg->collision_top == 0)
            rpg->character_vect.y -= 8;
        rpg->walk_toward = 0;
        rpg->character_rect.top = 0;
    }
    if (rpg->walk_backward == 1) {
        if (rpg->top_map == 0 && rpg->collision_bot == 0)
            sfView_move(rpg->view, (sfVector2f) {0, 8});
        if (rpg->collision_bot == 0)
            rpg->character_vect.y += 8;
        rpg->walk_backward = 0;
        rpg->character_rect.top = 64;
    }
}

void detect_collision(rpg_t *rpg)
{
    rpg->x_character = (((rpg->character_vect.x + 60) / 32) - 1);
    rpg->y_character = ((rpg->character_vect.y + 60) / 32);
    if (rpg->map[rpg->y_character - 1][rpg->x_character] != '0')
        rpg->collision_top = 1;
    if (rpg->map[rpg->y_character + 1][rpg->x_character] != '0')
        rpg->collision_bot = 1;
    if (rpg->map[rpg->y_character][rpg->x_character + 1] != '0')
        rpg->collision_right = 1;
    if (rpg->map[rpg->y_character][rpg->x_character - 1] != '0')
        rpg->collision_left = 1;
    if (rpg->map[rpg->y_character][rpg->x_character - 1] == '0')
        rpg->collision_left = 0;
    if (rpg->map[rpg->y_character][rpg->x_character + 1] == '0')
        rpg->collision_right = 0;
    if (rpg->map[rpg->y_character + 1][rpg->x_character] == '0')
        rpg->collision_bot = 0;
    if (rpg->map[rpg->y_character - 1][rpg->x_character] == '0')
        rpg->collision_top = 0;
}

void detect_if_board(rpg_t *rpg)
{
    if (rpg->character_vect.y < 540)
        rpg->top_map = 1;
    if (rpg->character_vect.y > 5985)
        rpg->top_map = 1;
    if (rpg->character_vect.x < 960)
        rpg->left_map = 1;
    if (rpg->character_vect.x > 5360)
        rpg->left_map = 1;
    if (rpg->character_vect.y > 540 && rpg->character_vect.y < 5985)
        rpg->top_map = 0;
    if (rpg->character_vect.x > 960 && rpg->character_vect.x < 5360)
        rpg->left_map = 0;
}