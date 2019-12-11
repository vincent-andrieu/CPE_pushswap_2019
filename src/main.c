/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** sort a list with rules
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "pushswap.h"

static list_t *args_to_list(int argc, char **argv, list_t *list)
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

static void free_list(list_t *list)
{
    if (list != NULL && list->next != NULL)
        free_list(list->next);
    free(list);
}

static void free_all(list_t *list_a, list_t *list_b, operations_t *operations)
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

static void concat_result(operations_t *operations, char const *str,
                        int str_len)
{
    for (int i = 0; i < str_len; i++)
        (operations->str + operations->len)[i] = str[i];
    operations->len += str_len;
    if (operations->len + str_len >= 1999990) {
        write(1, operations->str, operations->len);
        operations->len = 0;
    }
}

static void print_operations(list_t *list_b, operations_t *operations)
{
    bool first = true;

    while (list_b != NULL) {
        if (!first)
            concat_result(operations, " ", 1);
        first = false;
        concat_result(operations, OPE_PA, 2);
        list_b = list_b->next;
    }
    write(1, operations->str, operations->len);
}

static void rotate_list(list_t **list_a, operations_t *operations, int list_size)
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

static int do_swap(list_t *list_a, list_t *list_b, int list_size,
                    operations_t *operations)
{
    operations->str = malloc(sizeof(char) * 2000000);
    operations->len = 0;

    if (operations->str == NULL)
        return EXIT_FAILURE;
    for (; list_size > 1; list_size--) {
        rotate_list(&list_a, operations, list_size);
        concat_result(operations, pb(&list_a, &list_b), 2);
        concat_result(operations, " ", 1);
    }
    print_operations(list_b, operations);
    free_all(list_a, list_b, operations);
    return EXIT_SUCCESS;
}

static int pushswap(list_t *list_a, int argc)
{
    list_t *list_b = NULL;
    int exit_value;

    if (list_a == NULL)
        return EXIT_FAILURE;
    exit_value = do_swap(list_a, list_b, argc, malloc(sizeof(operations_t)));
    return exit_value;
}

int main(int argc, char **argv)
{
    list_t *list;

    if (argc <= 1) {
        my_put_error_str(MSG_NOT_ENOUGH_ARGS);
        return EXIT_NOT_ENOUGH_ARGS;
    }
    list = args_to_list(argc, argv, NULL);
    if (list == NULL)
        return EXIT_FAILURE;
    return pushswap(list, argc - 1);
}