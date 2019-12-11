/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** operations with flag rr
*/

#include <stddef.h>
#include "my.h"
#include "pushswap.h"

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