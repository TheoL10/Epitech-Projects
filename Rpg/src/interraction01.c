/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

void interraction_with_pnj(rpg_t *rpg)
{
    if (rpg->speech == 0) {
        interaction_with_lorenzo_quest(rpg);
        interaction_with_lorenzo(rpg);
        interaction_with_roi_hennok_one(rpg);
        interaction_with_booba(rpg);
        interaction_with_kaaris(rpg);
        interaction_with_lafouine(rpg);
        interaction_with_alkapote(rpg);
        interaction_with_alderiate(rpg);
        interaction_with_jason(rpg);
        interaction_with_the_rock(rpg);
        interaction_for_the_end(rpg);
    }
}