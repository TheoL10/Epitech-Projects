/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void do_free(rpg_t *rpg)
{
    sfMusic_destroy(rpg->music_fond);
    free(rpg);
}