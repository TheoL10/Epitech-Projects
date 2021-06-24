/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/struct.h"

void display_error(char **argv)
{
    my_printf("ls: impossible d'accéder à '");
    my_printf("%s", argv[1]);
    my_printf("': No such file or directory\n");
}

void init_struct(ls_t *ls)
{
    struct stat buffer;
    ls->size = buffer.st_size;
    ls->buffer = malloc((sizeof(char) * (ls->size + 1)));
    ls->dir = opendir("./");
}

void my_2(int argc, char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'a' && argc > 2)
        for (int i = 2; i != argc; i++)
            my_lsa2(opendir(argv[i]));
    if (argv[1][0] == '-' && argv[1][1] == 'd' && argc > 2)
        for (int i = 2; i != argc; i++)
            my_printf("%s\n", argv[i]);
}

int main(int argc, char **argv)
{
    ls_t *ls = malloc(sizeof(ls_t));
    init_struct(ls);

    if (argc == 1) {
        my_ls(ls);
        return (0);
    }
    my_2(argc, argv);
    if (argc > 1)
        ls->dir2 = opendir(argv[1]);
    if (argv[1][0] != '-' && ls->dir2 != NULL && argc > 1)
        for (int i = 1; i != argc; i++)
            my_ls2(opendir(argv[i]));
    if (argv[1][0] != '-' && ls->dir2 == NULL && argc == 2)
        display_error(argv);
    if (argv[1][0] == '-' && argv[1][1] == 'a' && argc == 2)
        my_lsa(ls);
    if (argv[1][0] == '-' && argv[1][1] == 'd' && argc == 2)
        my_lsd();
}