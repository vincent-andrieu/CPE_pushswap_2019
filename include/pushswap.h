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
#define MSG_ARG_NOT_INTEGER "An argument isn't an integer\n"
#define EXIT_SUCCESS 0

#define OPE_SA "sa"
#define OPE_SB "sb"
#define OPE_SC "sc"
#define OPE_PA "pa"
#define OPE_PB "pb"
#define OPE_RA "ra"
#define OPE_RB "rb"
#define OPE_RR "rr"
#define OPE_RRA "rra"
#define OPE_RRB "rrb"
#define OPE_RRR "rrr"

typedef struct list_s
{
    int size;
    int *tab;
} list_t;

void sa(list_t *list);
void sb(list_t *list);
void sc(list_t *list_a, list_t *list_b);
char *pa(list_t *list_a, list_t *list_b);
char *pb(list_t *list_a, list_t *list_b);
char *ra(list_t *list);
char *rb(list_t *list);
char *rr(list_t *list_a, list_t *list_b);
char *rra(list_t *list);
char *rrb(list_t *list);
char *rrr(list_t *list_a, list_t *list_b);

#endif