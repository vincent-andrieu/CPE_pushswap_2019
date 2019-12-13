/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocate memory and copy a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest;
    int len;

    if (src == NULL)
        return NULL;
    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return NULL;
    for (int i = 0; i <= len; i++)
        dest[i] = src[i];
    return dest;
}