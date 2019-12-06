/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** operations with flag p
*/

#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

static void delete_index(list_t *list, int i)
{
    list->size--;
    for (; i < list->size; i++)
        list->tab[i] = list->tab[i + 1];
}

char *pa(list_t *list_a, list_t *list_b)
{
    if (list_b->size >= 1) {
        list_a->size++;
        for (int i = list_a->size - 1; i > 0; i--)
            list_a->tab[i] = list_a->tab[i - 1];
        list_a->tab[0] = list_b->tab[0];
        delete_index(list_b, 0);
    }
    return OPE_PA;
}

char *pb(list_t *list_a, list_t *list_b)
{
    if (list_a->size >= 1) {
        list_b->size++;
        for (int i = list_b->size - 1; i > 0; i--)
            list_b->tab[i] = list_b->tab[i - 1];
        list_b->tab[0] = list_a->tab[0];
        delete_index(list_a, 0);
    }
    return OPE_PB;
}