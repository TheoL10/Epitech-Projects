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
#include <string.h>
#include <time.h>

typedef struct generator_s
{
    char **map;
    int line;
    int x;
    int y;
    int i;
    int j;
    int stars;
    int x_max;
    int y_max;
    int output;
    int north;
    int west;
    int max_lenght;
} generator_t;

void printstr(va_list *arg);
void printchar(va_list *arg);
void printnbr(va_list *arg);
void printnbrunsign(va_list *arg);
void printnbrhexa(va_list *arg);
void printnbrhexamaj(va_list *arg);
void finder_fonction(va_list *arg, char specifier);
int my_printf(char *sentence, ...);
void move_down(generator_t *gen, int i);
void finish(generator_t *gen, int i);
int error_handling(int ac, char **av);
int generate_perfect(generator_t *gen);
int create_map(generator_t *gen);
void resolve(generator_t *gen);
int malloc_maze(generator_t *gen, int x, int y);

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
char **my_str_to_wordtab(char *buffer, char c);
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
