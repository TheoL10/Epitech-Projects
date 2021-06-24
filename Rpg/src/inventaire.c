/*
** EPITECH PROJECT, 2021
** inventaire
** File description:
** inventaire
*/

#include "../lib/my/my.h"

void move_select_to_right(rpg_t *rpg)
{
    if (rpg->select_vect.x == (rpg->inventory_vect.x + 495)) {
        rpg->select_vect.x += 398;
    }
    if (((rpg->select_vect.x == (rpg->inventory_vect.x + 316))
    && (rpg->select_vect.y == (rpg->inventory_vect.y + 311)))
    || ((rpg->select_vect.x == (rpg->inventory_vect.x + 316))
    && (rpg->select_vect.y == (rpg->inventory_vect.y + 127)))) {
        rpg->select_vect.x += 179;
    }
    if (rpg->select_vect.x == (rpg->inventory_vect.x + 224)) {
        rpg->select_vect.x += 92;
    }
    if (rpg->select_vect.x == (rpg->inventory_vect.x + 129)) {
        rpg->select_vect.x += 95;
    }
    if (rpg->select_vect.x == (rpg->inventory_vect.x + 37)) {
        rpg->select_vect.x += 92;
    }
}

void move_select_to_left(rpg_t *rpg)
{
    if (rpg->select_vect.x == (rpg->inventory_vect.x + 129)) {
        rpg->select_vect.x -= 92;
    }
    if (rpg->select_vect.x == (rpg->inventory_vect.x + 224)) {
        rpg->select_vect.x -= 95;
    }
    if (rpg->select_vect.x == (rpg->inventory_vect.x + 316)) {
        rpg->select_vect.x -= 92;
    }
    if (rpg->select_vect.x == (rpg->inventory_vect.x + 495)) {
        rpg->select_vect.x -= 179;
    }
    if (rpg->select_vect.x == (rpg->inventory_vect.x + 893)) {
        rpg->select_vect.x -= 398;
    }
}

void move_select_to_down(rpg_t *rpg)
{
    if (rpg->select_vect.y == (rpg->inventory_vect.y + 219)) {
        rpg->select_vect.y += 92;
    }
    if (rpg->select_vect.y == (rpg->inventory_vect.y + 127)
    && rpg->select_vect.x != (rpg->inventory_vect.x + 893)
    && rpg->select_vect.x != (rpg->inventory_vect.x + 495)) {
        rpg->select_vect.y += 92;
    }
    if (rpg->select_vect.y == (rpg->inventory_vect.y + 127)) {
        rpg->select_vect.y += 184;
    }
    if (rpg->select_vect.y == (rpg->inventory_vect.y + 35)) {
        rpg->select_vect.y += 92;
    }
}

void move_select_to_up(rpg_t *rpg)
{
    if (rpg->select_vect.y == (rpg->inventory_vect.y + 127)
    && rpg->select_vect.x != (rpg->inventory_vect.x + 893)
    && rpg->select_vect.x != (rpg->inventory_vect.x + 495)) {
        rpg->select_vect.y -= 92;
    }
    if (rpg->select_vect.y == (rpg->inventory_vect.y + 219)) {
        rpg->select_vect.y -= 92;
    }
    if (rpg->select_vect.y == (rpg->inventory_vect.y + 311)
    && rpg->select_vect.x != (rpg->inventory_vect.x + 893)
    && rpg->select_vect.x != (rpg->inventory_vect.x + 495)) {
        rpg->select_vect.y -= 92;
    }
    if (rpg->select_vect.y == (rpg->inventory_vect.y + 311)) {
        rpg->select_vect.y -= 184;
    }
}