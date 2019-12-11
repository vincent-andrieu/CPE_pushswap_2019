/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** pushswap header
*/

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#define MSG_NOT_ENOUGH_ARGS "Not enough arguments\n"
#define EXIT_NOT_ENOUGH_ARGS 84
#define EXIT_SUCCESS 0

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

char *pa(list_t **list_a, list_t **list_b);
char *pb(list_t **list_a, list_t **list_b);
char *ra(list_t **list);
char *rra(list_t **list);

#endif