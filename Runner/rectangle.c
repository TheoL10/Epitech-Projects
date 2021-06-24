/*
** EPITECH PROJECT, 2020
** rectangle
** File description:
** rectangle
*/

#include "include/my.h"
#include "include/struct.h"

void rectangle(runner_t *run)
{
    run->rect_para = (sfIntRect) {0, 0, 1920, 1080};
    run->rect_para2 = (sfIntRect) {0, 0, 1920, 1080};
    run->rect_para3 = (sfIntRect) {0, 0, 1920, 1080};
    run->rect_animation = (sfIntRect) {0, 0, 157, 121};
    run->rect_score1 = (sfIntRect) {0, 0, 76, 65};
    run->rect_score2 = (sfIntRect) {0, 0, 76, 65};
    run->rect_score3 = (sfIntRect) {0, 0, 76, 65};
}