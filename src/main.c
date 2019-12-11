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

static list_t *args_to_list(int argc, char **argv)
{
    list_t *list = NULL;
    list_t *temp;
    list_t **last_list = malloc(sizeof(list_t *));

    if (last_list == NULL)
        return NULL;
    *last_list = NULL;
    for (int i = 1; i < argc; i++) {
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
        list = temp;
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

static void free_all(list_t *list_a, list_t *list_b, char *result)
{
    free(result);
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

static void concat_result(char *result, int *result_len, char const *str,
                        int str_len)
{
    for (int i = 0; i < str_len; i++)
        (result + *result_len)[i] = str[i];
    *result_len += str_len;
    if (*result_len + str_len >= 1999990) {
        write(1, result, *result_len);
        *result_len = 0;
    }
}

static void print_operations(list_t *list_b, char *result, int result_len)
{
    bool first = true;

    while (list_b != NULL) {
        if (!first)
            concat_result(result, &result_len, " ", 1);
        first = false;
        concat_result(result, &result_len, OPE_PA, 2);
        list_b = list_b->next;
    }
    write(1, result, result_len);
}

static int do_swap(list_t *list_a, list_t *list_b, int list_size)
{
    int smallest;
    char *result = malloc(sizeof(char) * 2000000);
    int result_len = 0;

    if (result == NULL)
        return EXIT_FAILURE;
    for (; list_size > 1; list_size--) {
        smallest = get_smallest(list_a->next, list_a->value, 1, 2);
        if (smallest > list_size / 2)
            for (int i = list_size; i >= smallest; i--) {
                concat_result(result, &result_len, rra(&list_a), 3);
                concat_result(result, &result_len, " ", 1);
            }
        else
            for (int i = 1; i < smallest; i++) {
                concat_result(result, &result_len, ra(&list_a), 2);
                concat_result(result, &result_len, " ", 1);
            }
        concat_result(result, &result_len, pb(&list_a, &list_b), 2);
        concat_result(result, &result_len, " ", 1);
    }
    print_operations(list_b, result, result_len);
    free_all(list_a, list_b, result);
    return EXIT_SUCCESS;
}

static int pushswap(list_t *list_a, int argc)
{
    list_t *list_b = NULL;
    int exit_value;

    if (list_a == NULL)
        return EXIT_FAILURE;
    exit_value = do_swap(list_a, list_b, argc);
    return exit_value;
}

int main(int argc, char **argv)
{
    list_t *list;

    if (argc <= 1) {
        my_put_error_str(MSG_NOT_ENOUGH_ARGS);
        return EXIT_NOT_ENOUGH_ARGS;
    }
    list = args_to_list(argc, argv);
    if (list == NULL)
        return EXIT_FAILURE;
    return pushswap(list, argc - 1);
}