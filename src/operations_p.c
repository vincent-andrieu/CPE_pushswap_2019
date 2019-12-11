/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** operations with flag p
*/

#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

char *pa(list_t **list_a, list_t **list_b)
{
    (*list_a)->previous = *list_b;
    (*list_b)->last = (*list_a)->last;
    (*list_b)->next->previous = NULL;
    *list_b = (*list_b)->next;
    (*list_a)->previous->next = *list_a;
    *list_a = (*list_a)->previous;
    return OPE_PA;
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