/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** operations with flag r
*/

#include "my.h"
#include "pushswap.h"

char *ra(list_t *list)
{
    int val_la = list->tab[0];

    for (int i = 0; i + 1 < list->size; i++)
        list->tab[i] = list->tab[i + 1];
    list->tab[list->size - 1] = val_la;
    return OPE_RA;
}

char *rb(list_t *list)
{
    int val_lb = list->tab[0];

    for (int i = 0; i + 1 < list->size; i++)
        list->tab[i] = list->tab[i + 1];
    list->tab[list->size - 1] = val_lb;
    return OPE_RB;
}

char *rr(list_t *list_a, list_t *list_b)
{
    int val_la = list_a->tab[0];
    int val_lb = list_b->tab[0];

    for (int i = 0; i + 1 < list_a->size || i + 1 < list_b->size; i++) {
        if (i + 1 < list_a->size)
            list_a->tab[i] = list_a->tab[i + 1];
        if (i + 1 < list_b->size)
            list_b->tab[i] = list_b->tab[i + 1];
    }
    list_a->tab[list_a->size - 1] = val_la;
    list_b->tab[list_b->size - 1] = val_lb;
    return OPE_RR;
}