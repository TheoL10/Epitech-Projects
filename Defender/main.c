/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"

void close_music2(defender_t *defender)
{
    sfMusic_destroy(defender->sws_sound5);
    sfMusic_destroy(defender->sws_sound6);
    sfMusic_destroy(defender->sws_sound7);
}

void close_music(defender_t *defender)
{
    sfMusic_destroy(defender->loop);
    sfMusic_destroy(defender->tower_sound);
    sfMusic_destroy(defender->tower_sound2);
    sfMusic_destroy(defender->tower_sound3);
    sfMusic_destroy(defender->tower_sound4);
    sfMusic_destroy(defender->tower_sound5);
    sfMusic_destroy(defender->tower_sound6);
    sfMusic_destroy(defender->tower_sound7);
    sfMusic_destroy(defender->ts_sound);
    sfMusic_destroy(defender->ts_sound2);
    sfMusic_destroy(defender->ts_sound3);
    sfMusic_destroy(defender->ts_sound4);
    sfMusic_destroy(defender->ts_sound5);
    sfMusic_destroy(defender->ts_sound6);
    sfMusic_destroy(defender->ts_sound7);
    sfMusic_destroy(defender->sws_sound);
    sfMusic_destroy(defender->sws_sound2);
    sfMusic_destroy(defender->sws_sound3);
    sfMusic_destroy(defender->sws_sound4);
    close_music2(defender);
}

void description(void)
{
    my_putstr("my_defender in CSFML\n");
    my_putstr("USAGE\n");
    my_putstr("./my_defender\n");
    my_putstr("You must defend the meadow by any means\n");
    my_putstr("Good Luck Have Fun !\n");
}

void call(defender_t *defender)
{
    position(defender);
    sprite(defender);
    texture(defender);
    sfSprite_setScale(defender->cs, (sfVector2f) {0.15, 0.15});
    sfSprite_setScale(defender->vie1, (sfVector2f) {0.6, 0.6});
    sfSprite_setScale(defender->vie2, (sfVector2f) {0.6, 0.6});
    sfSprite_setScale(defender->vie3, (sfVector2f) {0.6, 0.6});
    sfSprite_setScale(defender->shot, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(defender->shot2, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(defender->shot3, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(defender->shot4, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(defender->shot5, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(defender->shot6, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(defender->shot7, (sfVector2f) {0.5, 0.5});
    sfSprite_setScale(defender->up, (sfVector2f) {0.6, 0.6});
    sfSprite_setScale(defender->coin, (sfVector2f) {0.8, 0.8});
    defender->scoros = sfText_create();
    defender->font = sfFont_createFromFile("tools/bunny.ttf");
    defender->pos_text.x = 500;
    call2(defender);
}

int main(int argc, char **argv)
{
    defender_t *defender = malloc(sizeof(defender_t));

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        description();
        return (0);
    }
    sfVideoMode mode = {1920, 1080, 32};
    defender->window = sfRenderWindow_create(mode, "My_defender", sfResize |
    sfClose, NULL);
    call(defender);
    close_music(defender);
}