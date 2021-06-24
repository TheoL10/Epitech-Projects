/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "include/my.h"

char **my_str_to_word_tab(char *buffer, char c)
{
    int len_buff = (strlen(buffer) + 1);
    char **strtab = malloc(sizeof(char *) * (len_buff + 100));
    int pos_tablittl = 0;
    int pos_tabgen = 0;

    for (int a = 0; a != len_buff; a++)
        strtab[a] = malloc(sizeof(char) * (len_buff));
    for (int w = 0; buffer[w] != '\0'; w++) {
        if (buffer[w] != c) {
            strtab[pos_tabgen][pos_tablittl] = buffer[w];
            pos_tablittl++;
        }
        if (buffer[w] == c) {
            pos_tabgen++;
            pos_tablittl = 0;
        }
    }
    return (strtab);
}

int print_command(char *str, size_t size, char *buffer)
{
    write(1, str, strlen(str));
    if (getline(&buffer, &size, stdin) == -1)
        return (84);
    if (buffer[22] == 'T')
        print_command("STOP_SIMULATION\n", size, buffer);
    if (buffer[22] == 'L')
        print_command("STOP_SIMULATION\n", size, buffer);
    write(2, buffer, strlen(buffer));
    return (0);
}

int get_pos(char *buffer, n4s_t *n4s, size_t size)
{
    n4s->pos = my_str_to_word_tab(buffer, ':');
    int i = 0;
    for (; n4s->pos[i]; i++);
    if (i < 10)
        return (1);
    if (buffer[214] == 'T')
        print_command("STOP_SIMULATION\n", size, buffer);
    if (buffer[214] == 'L')
        print_command("STOP_SIMULATION\n", size, buffer);
    for (int j = 4; j < 35; j++) {
        n4s->rayon[j - 4] = atof(n4s->pos[j]);
    }
    return (0);
}

void get_info(char *str, size_t size, char *buffer, n4s_t *n4s)
{
    write(1, str, strlen(str));
    if (getline(&buffer, &size, stdin) == -1)
        return;
    if (get_pos(buffer, n4s, size) == 1)
        return;
}

int main(void)
{
    char *buffer = NULL;
    n4s_t *n4s = malloc(sizeof(n4s_t));
    n4s->left = 0;
    n4s->right = 0;
    size_t size = 0;
    print_command("START_SIMULATION\n", size, buffer);
    while (1) {
        get_info("GET_INFO_LIDAR\n", size, buffer, n4s);
        move_right(n4s, size, buffer);
        print_command("CAR_FORWARD:0.3\n", size, buffer);
    }
}