/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** operations with flag rr
*/

#include "my.h"
#include "pushswap.h"

char *rra(list_t *list)
{
    int val_l = list->tab[list->size - 1];

    for (int i = list->size - 1; i > 0; i--)
        list->tab[i] = list->tab[i - 1];
    list->tab[0] = val_l;
    return OPE_RRA;
}

char *rrb(list_t *list)
{
    int val_l = list->tab[list->size - 1];

    for (int i = list->size - 1; i > 0; i--)
        list->tab[i] = list->tab[i - 1];
    list->tab[0] = val_l;
    return OPE_RRB;
}

char *rrr(list_t *l_a, list_t *l_b)
{
    int val_la = l_a->tab[l_a->size - 1];
    int val_lb = l_b->tab[l_b->size - 1];

    for (int i = (l_a->size > l_b->size ? l_a->size : l_b->size) - 1;
    i >= 0; i--) {
        if (i <= l_a->size)
            l_a->tab[i] = l_a->tab[i - 1];
        if (i <= l_b->size)
            l_b->tab[i] = l_b->tab[i - 1];
    }
    l_a->tab[0] = val_la;
    l_b->tab[0] = val_lb;
    return OPE_RRR;
}