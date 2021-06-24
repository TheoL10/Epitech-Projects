/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"

void check_pipe(match_t *match)
{
    match->number_pipe = 0;

    for (int i = 1; match->buf[i + 1] != NULL; i++) {
        for (int a = 0; match->buf[i][a + 1] != 0; a++) {
            if (match->buf[i][a] == '|')
                match->number_pipe++;
        }
    }
}

int remove_stick(match_t *match, int arg2, int arg)
{
    match->count2 = 0;
    match->pipe = 0;
    remove_stick2(match);
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
    match->rm_line = my_getnbr(match->buf2);
    if (match->bug == 0)
        test(match, arg, arg2);
    return (0);
}

void continu2(match_t *match, int arg)
{
    check_pipe(match);
    ia_remove_stick(match);
    print_buf(match, arg);
    if (match->number_pipe == 0) {
        write(1, "I lost... snif... but I'll get", 30);
        write(1, " you next time! !\n", 18);
        match->loose = 2;
        match->count3 = 1;
    }
}

void continu1(match_t *match, int arg)
{
    print_buf(match, arg);
    if (match->number_pipe == 0) {
        write(1, "You lost, too bad...\n", 21);
        match->loose = 1;
        match->count3 = 1;
    }
    if (match->loose == 0)
        continu2(match, arg);
}

int main(int argc, char **argv)
{
    match_t *match = malloc(sizeof(match_t));
    if (argc != 3) {
        write(2, "You must enter 2 arguments max.\n", 32);
        return (84);
    } if (my_getnbr(argv[1]) < 2 || my_getnbr(argv[1]) > 99
    || my_getnbr(argv[2]) < 1)
        return (84);
    print_map(match, my_getnbr(argv[1]));
    check_pipe(match);
    how_lines(match);
    while (match->number_pipe > 0 || match->count3 != 1) {
        match->final = 0;
        remove_stick(match, my_getnbr(argv[2]), my_getnbr(argv[1]));
        if (match->bug == 0)
            continu1(match, my_getnbr(argv[1]));
    }
    if (match->loose == 1)
        return (2);
    if (match->loose == 2)
        return (1);
}