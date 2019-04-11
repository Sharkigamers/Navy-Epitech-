/*
** EPITECH PROJECT, 2019
** wrap.c
** File description:
** create all my wrap
*/

#include "my.h"

int wrap(int i, int f)
{
    static int save = 0;

    if (f == 1)
        save = i;
    return (save);
}

int wraptwo(int i, int f)
{
    static int save = 0;

    if (f == 1)
        save = i;
    return (save);
}

int wrapthree(int i, int f)
{
    static int save = 0;

    if (i == 1 && save == 1)
        save = 2;
    else if (f == 1)
        save = i;
    return (save);
}
