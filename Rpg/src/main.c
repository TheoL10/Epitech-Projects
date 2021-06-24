/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void analyse_event(rpg_t *rpg)
{
    skip_cut_scene(rpg);
    close_the_window(rpg);
    interraction_with_pnj(rpg);
    move_hand_selection_in_pause_menu(rpg);
    move_hand_selection_in_main_menu(rpg);
    move_the_character_in_game(rpg);
    wich_button_when_enter_pressed(rpg);
    close_the_pause_menu(rpg);
    open_the_inventaire(rpg);
    move_selection_from_inv(rpg);
    move_hand_selection_in_menu_combat_alde(rpg);
    move_hand_selection_in_menu_combat_jason(rpg);
    move_hand_selection_in_menu_combat_the_rock(rpg);
    quit_end_menu(rpg);
}

void gameloop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            analyse_event(rpg);
        sfRenderWindow_display(rpg->window);
        go_to_everything(rpg);
    }
}

int main(void)
{
    int output = 0;
    rpg_t *rpg = malloc(sizeof(rpg_t));
    rpg->volume = 50;

    output = init_everything(rpg);
    sfVideoMode mode = {1920, 1080, 32};
    rpg->window = sfRenderWindow_create(mode, "Pokemon Island", sfClose, NULL);
    sfMusic_play(rpg->music_fond);
    gameloop(rpg);
    sfRenderWindow_destroy(rpg->window);
    do_free(rpg);
    return (output);
}