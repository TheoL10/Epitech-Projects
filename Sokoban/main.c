/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"

void helper(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map file representing the warehouse map, containing '#' ");
    my_printf("for walls,\n");
    my_printf("         'P' for the player, 'X' for boxes and 'O' for ");
    my_printf("storage locations.\n");
}

int error_gestion(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->buf[i] != '\0'; i++)
        if ((sokoban->buf[i] != ' ' && sokoban->buf[i] != '\n'
        && sokoban->buf[i] != '#' && sokoban->buf[i] != 'X'
        && sokoban->buf[i] != 'O' && sokoban->buf[i] != 'P')
        || (sokoban->count_p != 1)) {
            sokoban->condition_return = 2;
            sokoban->count2 = 1;
        }
    return (0);
}

void game(sokoban_t *sokoban)
{
    clear();
    find_position_p(sokoban);
    printw(sokoban->buf);
    find_size_line(sokoban);
    sokoban->condition = getch();
    movement_player(sokoban);
    refresh();
}

void read_file(sokoban_t *sokoban)
{
    sokoban->buf = malloc(sizeof(char) * (sokoban->size + 1));
    sokoban->reset = malloc(sizeof(char) * (sokoban->size + 1));
    if (read(sokoban->file, sokoban->buf, sokoban->size) == -1) {
        sokoban->condition_return = 2;
        sokoban->count2 = 1;
    }
    my_strcpy(sokoban->reset, sokoban->buf);
    initscr();
    keypad(stdscr, TRUE);
    error2(sokoban);
    find_p(sokoban);
    find_box(sokoban);
    error_gestion(sokoban);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        helper();
        return (0);
    } sokoban_t *sokoban = malloc(sizeof(sokoban_t));
    struct stat buffer;
    sokoban->file = open(argv[1], O_RDONLY);
    stat(argv[1], &buffer);
    sokoban->size = buffer.st_size;
    read_file(sokoban);
    while (sokoban->count2 != 1)
        game(sokoban);
    endwin();
    if (sokoban->condition_return == 0)
        return (1);
    if (sokoban->condition_return == 2)
        return (84);
    else
        return (0);
}