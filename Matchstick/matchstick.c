/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** matchstick
*/

#include "include/my.h"
#include "include/struct.h"

void print_map(match_t *match, int arg)
{
    match->line = arg * 2 + 1;
    int result = arg + 2;
    int number = 1;
    int jump = arg - 1;

    match->buf = malloc(sizeof(char *) * (arg + 4));
    for (int a = 0; a < arg + 3; a++)
        match->buf[a] = malloc(sizeof(char) * (match->line + 3));
    first_line(match);
    mid_map(match, arg, number, jump);
    last_line(match, result);
    print_buf(match, arg);
}

void first_line(match_t *match)
{
    for (int b = 0; b != match->line; b++)
            match->buf[0][b] = '*';
    match->buf[0][match->line] = '\n';
    match->buf[0][match->line + 1] = '\0';
}

void mid_map(match_t *match, int arg, int number, int jump)
{
    int pipe_number = 0;
    int y = 1;

    for (int c = 1; c != arg + 1; c++) {
        match->buf[c][0] = '*';
        for (int d = 0; d < jump; d++, number++)
            match->buf[c][number] = ' ';
        for (int e = 0; e != y; e++, number++) {
            match->buf[c][number] = '|';
            pipe_number += 1;
        }
        for (int f = 0; f <= jump; f++, number++)
            match->buf[c][number] = ' ';
        match->buf[c][match->line - 1] = '*';
        match->buf[c][match->line] = '\n';
        match->buf[c][match->line + 1] = '\0';
        number = 1;
        jump--;
        y += 2;
    }
}

void last_line(match_t *match, int result)
{
    for (int g = 0; g != match->line; g++)
        match->buf[result - 1][g] = '*';
    match->buf[result - 1][match->line] = '\n';
    match->buf[result - 1][match->line + 1] = '\0';
}

void print_buf(match_t *match, int arg)
{
    for (int i = 0; i != arg + 2; i++)
        my_putstr(match->buf[i]);
}