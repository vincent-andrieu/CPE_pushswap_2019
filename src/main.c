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

static int pushswap(list_t *list_a, int list_size)
{
    list_t *list_b = NULL;
    operations_t *operations = malloc(sizeof(operations_t));

    if (operations == NULL)
        return EXIT_FAILURE;
    operations->str = malloc(sizeof(char) * MALLOC_SIZE_RESULT);
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
    my_putchar('\n');
    return EXIT_SUCCESS;
}

void concat_result(operations_t *operations, char const *str, int str_len)
{
    for (int i = 0; i < str_len; i++)
        (operations->str + operations->len)[i] = str[i];
    operations->len += str_len;
    if (operations->len + str_len >= MALLOC_SIZE_RESULT - 5) {
        write(1, operations->str, operations->len);
        operations->len = 0;
    }
}

int main(int argc, char **argv)
{
    list_t *list_a;

    if (argc <= 1) {
        my_put_error_str(MSG_NOT_ENOUGH_ARGS);
        return EXIT_NOT_ENOUGH_ARGS;
    }
    list_a = args_to_list(argc, argv, NULL);
    if (list_a == NULL)
        return EXIT_FAILURE;
    if (is_sorted(list_a->next, list_a->value)) {
        free(list_a->last);
        free_list(list_a);
        return EXIT_SUCCESS;
    }
    return pushswap(list_a, argc - 1);
}