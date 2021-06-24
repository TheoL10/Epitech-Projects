/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"

void description(void)
{
    my_putstr("my_runner in CSFML\n");
    my_putstr("USAGE\n");
    my_putstr("./my_runner map.txt\n");
    my_putstr("Left the Game = 'q'\n");
    my_putstr("You can jump with 'space'\n");
    my_putstr("you win if you jump over all ");
    my_putstr("the obstacles or reach a score of 999\n");
    my_putstr("You can modify the map ('X' = obstacles)\n");
    my_putstr("Good Luck Have Fun !\n");
}

void call(runner_t *run)
{
    // clock(run);
    // position(run);
    sprite(run);
    texture(run);
    // setscale(run);
    set_texture(run);
    // sfMusic_play(run->mine);
    game_loop(run);
    // kill(run);
}

int main(int argc, char **argv)
{
    runner_t *run = malloc(sizeof(runner_t));

    // if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
    //     description();
    //     return (0);
    // }
    // if (argc != 2)
    //     return (84);
    // readmap(run, argv);
    // run->obs2 = 1;
    // run->speed = 1;
    // for (int s = 0; run->buf[s] != '\0'; s++)
    //     if (run->buf[s] == 'X')
    //         run->nbx++;
    sfVideoMode mode = {1920, 1080, 32};
    run->window = sfRenderWindow_create(mode, "My_runner", sfResize |
    sfClose, NULL);
    call(run);
}