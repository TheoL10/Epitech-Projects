/*
** EPITECH PROJECT, 2020
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX         2
#define OP_SUB_IDX          3
#define OP_NEG_IDX          3
#define OP_MULT_IDX         4
#define OP_DIV_IDX          5
#define OP_MOD_IDX          6
#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84
#define EXIT_EXPR     84
#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *op_base(char const *av, char const *base, char *res, int size);
char *digit_base(char const *av, char const *base, char *res, int size);
char *rev_op_base(char *res, char const *base, int size);
char *rev_digit_base(char *res, char const *base, int size);
char digit_base2(char const *av, char const *base, char res, int i);
char rev_digit_base2(char const *base, char res);
void addition(char *av, int op, int end);
int my_atoi(char **str);
int multipl(char *res, int op, int after, int len_after);
void substraction(char *av, int op, int end, int cnt);
int add_nb1(int i1, int nb1, char *before);
int add_nb2(int i2, int nb2, char *after);
int is_sup(char *before, char *after);
char *sub2(char *before, char *after, int nb1, int nb2);
char *sub3(char *before, char *after, int nb1, int nb2);
char *get_before(char *av, int op);
int replace0(char *res, int count, int op);
char *get_result(char *res);
int replace(char *result, char *res, int count);
void error(void);
int error3(int ac, char **av);
int check_ops_base(char const *ops, char const *b);
char *eval_expr(char *av);
char *add_inf(char *before, char *after, int nb1, int nb2);
char *sub_inf(char *before, char *after);
void is_neg(char *av, char *before, char *after, int op);
void primary(char *res);
void secondary(char *av);

#endif
