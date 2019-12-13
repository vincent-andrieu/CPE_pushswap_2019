/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** pushswap header
*/

#include <stdbool.h>

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#define MSG_NOT_ENOUGH_ARGS "Not enough arguments\n"
#define EXIT_NOT_ENOUGH_ARGS 84
#define EXIT_SUCCESS 0
#define MALLOC_SIZE_RESULT 50000000

#define OPE_PA "pa"
#define OPE_PB "pb"
#define OPE_RA "ra"
#define OPE_RRA "rra"

typedef struct list_s
{
    int value;
    struct list_s *next;
    struct list_s **last;
    struct list_s *previous;
} list_t;

typedef struct operations_s
{
    char *str;
    int len;
} operations_t;

list_t *args_to_list(int argc, char **argv, list_t *list);
void free_list(list_t *list);
void free_all(list_t *list_a, list_t *list_b, operations_t *operations);
void rotate_list(list_t **list_a, operations_t *operations, int list_size);
void concat_result(operations_t *operations, char const *str, int str_len);
bool is_sorted(list_t *list, int last_value);

char *pa(list_t **list_a, list_t **list_b);
char *pb(list_t **list_a, list_t **list_b);
char *ra(list_t **list);
char *rra(list_t **list);

#endif