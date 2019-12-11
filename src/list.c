/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** manage lists
*/

#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

list_t *args_to_list(int argc, char **argv, list_t *list)
{
    list_t *temp;
    list_t **last_list = malloc(sizeof(list_t *));

    if (last_list == NULL)
        return NULL;
    *last_list = NULL;
    for (int i = 1; i < argc; i++, list = temp) {
        temp = malloc(sizeof(list_t));
        if (temp == NULL
        || !my_str_isnum(argv[i][0] == '-' ? argv[i] + 1 : argv[i]))
            return NULL;
        temp->value = my_getnbr(argv[i]);
        temp->next = list;
        *last_list = *last_list == NULL ? temp : *last_list;
        temp->last = last_list;
        if (temp->next != NULL)
            temp->next->previous = temp;
    }
    list->previous = NULL;
    return list;
}

void free_list(list_t *list)
{
    if (list != NULL && list->next != NULL)
        free_list(list->next);
    free(list);
}

void free_all(list_t *list_a, list_t *list_b, operations_t *operations)
{
    free(operations->str);
    free(operations);
    free(list_a->last);
    free_list(list_a);
    free_list(list_b);
}

static int get_smallest(list_t *list, int small_val, int small_i, int index)
{
    if (list == NULL)
        return small_i;
    if (list->value < small_val) {
        small_i = index;
        small_val = list->value;
    }
    return get_smallest(list->next, small_val, small_i, index + 1);
}

void rotate_list(list_t **list_a, operations_t *operations, int list_size)
{
    int smallest = get_smallest((*list_a)->next, (*list_a)->value, 1, 2);

    if (smallest > list_size / 2)
        for (int i = list_size; i >= smallest; i--) {
            concat_result(operations, rra(list_a), 3);
            concat_result(operations, " ", 1);
        }
    else
        for (int i = 1; i < smallest; i++) {
            concat_result(operations, ra(list_a), 2);
            concat_result(operations, " ", 1);
        }
}