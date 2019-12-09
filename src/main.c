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

static int *args_to_int_tab(int argc, char **argv)
{
    int *tab = malloc(sizeof(int) * (argc - 1));

    if (tab == NULL)
        return NULL;
    for (int i = 1; i < argc; i++) {
        if (!my_str_isnum(argv[i][0] == '-' ? argv[i] + 1 : argv[i])) {
            my_put_error_str(MSG_ARG_NOT_INTEGER);
            return NULL;
        }
        tab[i - 1] = my_getnbr(argv[i]);
    }
    return tab;
}

static void free_lists(list_t *list_a, list_t *list_b)
{
    free(list_a->tab);
    free(list_a);
    free(list_b->tab);
    free(list_b);
}

static int get_index_smallest(list_t *list, int smallest, int i)
{
    if (i >= list->size)
        return smallest;
    if (list->tab[i] < list->tab[smallest])
        smallest = i;
    return get_index_smallest(list, smallest, i + 1);
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

static int do_swap(list_t *list_a, list_t *list_b)
{
    int smallest;
    bool first = true;
    char *result = malloc(sizeof(char) * 2000000);
    int result_len = 0;

    if (result == NULL)
        return EXIT_FAILURE;
    while (list_a->size > 0) {
        smallest = get_index_smallest(list_a, 0, 1);
        if (smallest > list_a->size / 2)
            for (int i = list_a->size; i > smallest; i--) {
                concat_result(result, &result_len, rra(list_a), 3);
                concat_result(result, &result_len, " ", 1);
            }
        else
            for (int i = 0; i < smallest; i++) {
                concat_result(result, &result_len, ra(list_a), 2);
                concat_result(result, &result_len, " ", 1);
            }
        concat_result(result, &result_len, pb(list_a, list_b), 2);
        concat_result(result, &result_len, " ", 1);
    }
    for (int i = list_b->size; i > 0; i--) {
        if (!first)
            concat_result(result, &result_len, " ", 1);
        first = false;
        concat_result(result, &result_len, pa(list_a, list_b), 2);
    }
    write(1, result, result_len);
    free(result);
    return EXIT_SUCCESS;
}

static int pushswap(list_t *list_a)
{
    list_t *list_b = malloc(sizeof(list_t));
    int exit_value;

    if (list_a == NULL || list_b == NULL)
        return EXIT_FAILURE;
    list_b->tab = malloc(sizeof(int) * list_a->size);
    list_b->size = 0;
    if (list_b->tab == NULL)
        return EXIT_FAILURE;
    exit_value = do_swap(list_a, list_b);
    free_lists(list_a, list_b);
    return exit_value;
}

int main(int argc, char **argv)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return EXIT_FAILURE;
    if (argc <= 1) {
        my_put_error_str(MSG_NOT_ENOUGH_ARGS);
        return EXIT_NOT_ENOUGH_ARGS;
    }
    list->tab = args_to_int_tab(argc, argv);
    if (list->tab == NULL) {
        free(list);
        return EXIT_FAILURE;
    }
    list->size = argc - 1;
    return pushswap(list);
}