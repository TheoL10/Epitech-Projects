/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include "include/my.h"
#include "include/struct.h"

void menu(hunter_t *hunter)
{
    if (hunter->menu == 0) {
        boom(hunter);
        set_position_menu1(hunter);
        button(hunter);
    }
    if (hunter->menu == 1) {
        boom(hunter);
        window_game(hunter);
    }
    if (hunter->menu == 2) {
        boom(hunter);
        set_position_menu2(hunter);
        button2(hunter);
    }
}