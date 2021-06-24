/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Game created by Theo and GuillaumeP
*/

#include "../lib/my/my.h"

char **open_file(char *filepath)
{
    char *buffer;
    struct stat s;
    size_t size;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return (NULL);
    stat(filepath, &s);
    size = s.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    if (buffer == NULL)
        return (NULL);
    if (read(fd, buffer, size) == -1)
        return (NULL);
    buffer[size] = '\0';
    close(fd);

    char **map = my_str_to_chartab(buffer);
    free(buffer);
    return (map);
}

char **open_file_dialog(char *filepath)
{
    char *buffer;
    struct stat s;
    size_t size;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return (NULL);
    stat(filepath, &s);
    size = s.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    if (buffer == NULL)
        return (NULL);
    if (read(fd, buffer, size) == -1)
        return (NULL);
    buffer[size] = '\0';
    close(fd);

    char **map = my_str_to_chartab_dialog(buffer);
    free(buffer);
    return (map);
}