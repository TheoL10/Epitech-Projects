/*
** EPITECH PROJECT, 2021
** direction
** File description:
** direction
*/

#include "include/my.h"

void move_left(n4s_t *n4s, size_t size, char *buffer)
{
    if ((n4s->rayon[30] <= 400) && n4s->left == 0
    && (n4s->rayon[30] <= n4s->rayon[0])) {
        print_command("WHEELS_DIR:0.1\n", size, buffer);
        n4s->left = 1;
    }
    if ((n4s->rayon[30] <= 300) && n4s->left == 1
    && (n4s->rayon[30] <= n4s->rayon[0])) {
        print_command("WHEELS_DIR:0.2\n", size, buffer);
        n4s->left = 2;
    }
    if ((n4s->rayon[30] <= 200) && n4s->left == 2
    && (n4s->rayon[30] <= n4s->rayon[0])) {
        print_command("WHEELS_DIR:0.4\n", size, buffer);
        n4s->left = 3;
    }
    if (((n4s->rayon[30]) >= 400) && n4s->left > 0) {
        print_command("WHEELS_DIR:0\n", size, buffer);
        n4s->left = 0;
    }
}

void move_right(n4s_t *n4s, size_t size, char *buffer)
{
    if ((n4s->rayon[0] <= 200) && n4s->right == 2
    && (n4s->rayon[30] >= n4s->rayon[0])) {
        print_command("WHEELS_DIR:-0.4\n", size, buffer);
        n4s->right = 3;
    }
    if ((n4s->rayon[0] <= 300) && n4s->right == 1
    && (n4s->rayon[30] >= n4s->rayon[0])) {
        print_command("WHEELS_DIR:-0.3\n", size, buffer);
        n4s->right = 2;
    }
    if ((n4s->rayon[0] <= 400) && n4s->right == 0
    && (n4s->rayon[30] >= n4s->rayon[0])) {
        print_command("WHEELS_DIR:-0.2\n", size, buffer);
        n4s->right = 1;
    }
    if (((n4s->rayon[0]) >= 500) && n4s->right > 0) {
        print_command("WHEELS_DIR:0\n", size, buffer);
        n4s->right = 0;
    }
    move_left(n4s, size, buffer);
}