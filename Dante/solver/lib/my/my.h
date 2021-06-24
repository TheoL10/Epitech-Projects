/*
** EPITECH PROJECT, 2020
** my
** File description:
** task02 day09
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ncurses.h>
#include <sys/stat.h>
#include "struct.h"

typedef struct match_s
{
    char **map;
    int line;
    int line_played;
    int colons;
    int match_played;
    int stars;
    int finish;
    int match_ia;
    int line_ia;

}match_t;

int read_map(solver_t *solv, char **av);
void h_lines_colums(solver_t *solv);
int find_solution(solver_t *solv, int y, int x);
void print_buf(solver_t *solv);
int error_gestion(solver_t *solv);
char **my_str_to_wordtab(char *buffer, char c);

void printstr(va_list *arg);
void printchar(va_list *arg);
void printnbr(va_list *arg);
void printnbrunsign(va_list *arg);
void printnbrhexa(va_list *arg);
void printnbrhexamaj(va_list *arg);
void finder_fonction(va_list *arg, char specifier);
int my_printf(char *sentence, ...);

typedef struct struct_s
{
    char coco;
    void (*functiontab)(va_list *);

}struct_t;

static const struct_t spe[] =
{
    {'s', &printstr},
    {'c', &printchar},
    {'d', &printnbr},
    {'i', &printnbr},
    {'u', &printnbrunsign},
    {'x', &printnbrhexa},
    {'X', &printnbrhexamaj},
    {'\0', NULL}
};

int my_str_is_pos(char const *str);
char **my_str_to_chartab(char *buffer);
void my_dec_to_hex_min(int decimalnbr);
void my_dec_to_hex_maj(int decimalnbr);
int substraction(char *nb1, char *nb2);
int display(char *finalresult, int signe);
int  my_compute_power_rec(int nb , int p);
int  my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(const char *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int b);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest , char  const *src , int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
