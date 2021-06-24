/*
** EPITECH PROJECT, 2021
** matchstick2
** File description:
** matchstick2
*/

#include "include/my.h"
#include "include/struct.h"

void ia_remove_stick(match_t *match)
{
    for (int i = match->h_lines + 1; i != 0; i--) {
        for (int y = match->line; y != 0; y--) {
            if (match->buf[i][y] == '|' && match->final == 0) {
                match->buf[i][y] = ' ';
                match->ia_line = i;
                match->number_pipe -= 1;
                match->final = 1;
            }
        }
    }
    write(1, "\nAI's turn...\n", 14);
    my_putstr("AI removed ");
    my_put_nbr(1);
    my_putstr(" match(es) from line ");
    my_put_nbr(match->ia_line);
    my_putchar('\n');
}

void how_lines(match_t *match)
{
    for (int i = 1; match->buf[i][0] != '\0'; i++) {
        for (int y = 1; match->buf[i][y] != '\0'; y++) {
            if (match->buf[i][y] == '\n')
                match->h_lines++;
        }
    }
    match->h_lines -= 1;
}

void error(match_t *match, int arg, int arg2)
{
    if (match->matches == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        match->gest = 1;
        match->pipe = 0;
        remove_stick(match, arg2, arg);
        match->gest = 0;
        return (0);
    }
}