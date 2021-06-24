/*
** EPITECH PROJECT, 2021
** remove_stick
** File description:
** remove_stick
*/

#include "include/my.h"
#include "include/struct.h"

int remove_stick2(match_t *match)
{
    if (match->gest == 0)
        write(1, "\nYour turn:\n", 12);
    if (match->gest2 == 1)
        write(1, "\nLine: ", 7);
    if (match->gest2 == 0)
        write(1, "Line: ", 6);
    if (getline(&match->buf2, &match->size, stdin) == -1) {
        match->count3 = 1;
        match->number_pipe = 0;
        match->bug = 1;
        return (0);
    }
    return (0);
}

int remove_stick3(match_t *match, int arg, int arg2)
{
    write(1, "Matches: ", 9);
    if (getline(&match->buf2, &match->size, stdin) == -1) {
        match->count3 = 1;
        match->number_pipe = 0;
        match->bug = 1;
        return (0);
    }
    for (int i = 0; match->buf2[i] != '\0'; i++) {
        if ((match->buf2[i] < '0' || match->buf2[i] > '9')
        && match->buf2[i] != '\n' && match->count3 == 0) {
            write(1, "Error: invalid input (positive number expected)\n", 48);
            match->gest = 1;
            match->pipe = 0;
            remove_stick(match, arg2, arg);
            match->gest = 0;
            return (0);
        }
    }
    return (0);
}

int remove_stick4(match_t *match, int arg, int arg2)
{
    match->rm_pipe = my_getnbr(match->buf2);
    if (match->rm_pipe > arg2) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(arg2);
        write(1, " matches per turn\n", 17);
        match->gest = 1;
        match->gest2 = 1;
        remove_stick(match, arg2, arg);
        match->gest = 0;
        match->gest2 = 0;
        return (0);
    }
    match->matches = match->rm_pipe;
    match->lines = match->rm_line;
    if (match->lines > 0) {
        for (int i = 0; match->buf[match->lines][i] != '\n'; i++) {
            if (match->buf[match->lines][i] == '|')
                match->pipe++;
        }
    } return (0);
}

void remove_stick5(match_t *match, int arg, int arg2)
{
    error(match, arg, arg2);
    if (match->count3 == 0) {
        for (int i = match->line - 2; i != 0; i--) {
            if (match->buf[match->rm_line][i] == '|' && match->rm_pipe > 0) {
                match->buf[match->rm_line][i] = ' ';
                match->rm_pipe -= 1;
                match->number_pipe -= 1;
                match->count2 = 1;
            }
        }
        if (match->count2 == 1) {
            write(1, "Player removed ", 15);
            my_put_nbr(match->matches);
            write(1, " match(es) from line ", 21);
            my_put_nbr(match->lines);
            my_putchar('\n');
        }
        match->count2 = 2;
    }
}

void test(match_t *match, int arg, int arg2)
{
    if (match->rm_line > match->h_lines || match->rm_line == 0) {
        write(1, "Error: this line is out of range\n", 33);
        match->gest = 1;
        match->gest2 = 0;
        match->pipe = 0;
        remove_stick(match, arg2, arg);
        match->gest = 0;
        return (0);
    } remove_stick3(match, arg, arg2);
    remove_stick4(match, arg, arg2);
    if (match->matches > match->pipe && match->count3 == 0
    || match->matches < 0 && match->count3 == 0) {
        write(1, "Error: not enough matches on this line\n", 39);
        match->gest = 1;
        match->gest2 = 0;
        remove_stick(match, arg2, arg);
        match->gest = 0;
        return (0);
    } if (match->count2 == 0)
        remove_stick5(match, arg, arg2);
}