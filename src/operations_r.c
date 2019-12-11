/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** operations with flag r
*/

#include <stddef.h>
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