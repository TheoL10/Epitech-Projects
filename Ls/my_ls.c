/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls
*/

#include "include/my.h"
#include "include/struct.h"

void my_ls(ls_t *ls)
{
    struct dirent *dirent;

    while ((dirent = readdir(ls->dir)) != NULL)
        if (dirent->d_name[0] != '.')
            my_printf("%s\n", dirent->d_name);
}

void my_ls2(DIR *directories)
{
    struct dirent *dirent;

    while ((dirent = readdir(directories)) != NULL)
        if (dirent->d_name[0] != '.')
            my_printf("%s\n", dirent->d_name);
}

void my_lsa(ls_t *ls)
{
    struct dirent *dirent;

    while ((dirent = readdir(ls->dir)) != NULL)
        my_printf("%s\n", dirent->d_name);
}

void my_lsa2(DIR *directories)
{
    struct dirent *dirent;

    while ((dirent = readdir(directories)) != NULL)
        my_printf("%s\n", dirent->d_name);
}

void my_lsd(void)
{
    my_printf(".\n");
}