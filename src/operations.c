/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** operations with flag p
*/

#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

char *ra(list_t **list)
{
    *list = (*list)->next;
    (*list)->previous->next = NULL;
    (*list)->previous->previous = *((*list)->last);
    (*((*list)->last))->next = (*list)->previous;
    (*list)->previous = NULL;
    (*(*list)->last) = (*((*list)->last))->next;
    return OPE_RA;
}

char *rra(list_t **list)
{
    (*((*list)->last))->previous->next = NULL;
    (*((*list)->last))->next = *list;
    (*list)->previous = *((*list)->last);
    *((*list)->last) = (*((*list)->last))->previous;
    *list = (*list)->previous;
    (*list)->previous = NULL;
    return OPE_RRA;
}

char *pb(list_t **list_a, list_t **list_b)
{
    if ((*list_b) != NULL) {
        (*list_b)->previous = *list_a;
        (*list_a)->last = (*list_b)->last;
        if ((*list_a)->next != NULL)
            (*list_a)->next->previous = NULL;
        (*list_a) = (*list_a)->next;
        (*list_b)->previous->next = *list_b;
        *list_b = (*list_b)->previous;
    } else {
        *list_a = (*list_a)->next;
        (*list_a)->previous->next = *list_b;
        *list_b = (*list_a)->previous;
        (*list_a)->previous = NULL;
    }
    return OPE_PB;
}