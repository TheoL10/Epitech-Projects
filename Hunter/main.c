/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "include/struct.h"
#include "include/my.h"

void kill_game(hunter_t *hunter, texture_hunter_t *text_hunter)
{
    sfMusic_destroy(hunter->boom);
    sfSprite_destroy(hunter->sprite_mouse);
    sfTexture_destroy(text_hunter->text_mouse);
}

void description(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
    my_putstr("Duck hunt remastered in CSFML\n");
    my_putstr("USAGE\n");
    my_putstr("./my_hunter\n");
    my_putstr("Left the Game = 'q'\n");
    my_putstr("You can lose only one life per wave\n");
    my_putstr("The Final Score is displayed ");
    my_putstr("on terminal at the end of the Game\n");
    my_putstr("Good Luck Have Fun !\n");
    }
}

void score(hunter_t *hunter)
{
    my_putchar('\n');
    my_putstr("Final Score : ");
    my_put_nbr(hunter->count);
    my_putchar('\n');
    my_putchar('\n');
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        description(argv);
        return (0);
    }
    hunter_t *hunter = malloc(sizeof(hunter_t));
    texture_hunter_t *text_hunter = malloc(sizeof(texture_hunter_t));
    sfVideoMode mode = {1920, 1080, 32};
    hunter->bird = (sfIntRect) {0, 0, 62, 65};
    hunter->window = sfRenderWindow_create(mode, "Lorenzo Hunt", sfResize
    | sfClose, NULL);
    sprite(hunter);
    audio(hunter);
    position(hunter);
    sfSprite_setScale(hunter->sprite_bird, (sfVector2f) {2.5, 2.5});
    sfSprite_setScale(hunter->sprite_bm, (sfVector2f) {1, 1});
    texture(text_hunter);
    set_texture(hunter, text_hunter);
    clock(hunter);
    game_loop(hunter, text_hunter);
    score(hunter);
}