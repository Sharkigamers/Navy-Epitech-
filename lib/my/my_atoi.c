/*
** EPITECH PROJECT, 2018
** my_atoi.c
** File description:
** convert a str into a int
*/

#include <stdlib.h>

int my_strlen(char *s);

int my_atoi(char *s)
{
    int i = my_strlen(s);
    int res = 0;
    int retenue = 1;

    if (s == NULL)
        return (84);
    while (i != 0) {
        retenue = retenue * 10;
        i = i - 1;
    }
    while (retenue > 1) {
        retenue = retenue / 10;
        res = res + (s[i] - 48) * retenue;
        i = i + 1;
    }
    return (res);
}
