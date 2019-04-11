/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get next line of a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../printf/include/my.h"

char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_memset(char *res, char c, int size);

char *last_res(char *res, int *nb_rep, int *len, int i)
{
    res[i] = '\0';
    *nb_rep = 1;
    *len = 0;
    return (res);
}

void cond_main(char **res, int nb_rep)
{
    char *saver = NULL;

    saver = my_strdup(*res);
    free(*res);
    *res = malloc(READ_SIZE * (nb_rep + 1));
    *res = my_strcpy(*res, saver);
    free(saver);
}

int cond_chara(char *chara, char **save_res, int *len)
{
    chara[0] = (*save_res)[0];
    (*save_res)++;
    (*len)--;
    if (*len == 0) {
        *len = 0;
        return (1);
    }
    return (0);
}

int first_chara(int fd, char *chara, int *len)
{
    static char *save_res = NULL;
    char *res = malloc(READ_SIZE + 1);

    my_memset(res, '\0', READ_SIZE + 1);
    if (*len == 0) {
        *len = read(fd, res, READ_SIZE);
        save_res = res;
        if (save_res[1] == '\0' || save_res[0] == '\0') {
            *chara = save_res[0];
            save_res++;
            (*len)--;
            return (0);
        }
    }
    if (cond_chara(chara, &save_res, len) == 1)
        return (1);
    return (0);
}

char *get_next_line(int fd)
{
    static int nb_rep = 1;
    static int len = 0;
    char *res = malloc(READ_SIZE + 1);
    char chara = 0;
    int i = 0;

    if (res == NULL)
        return NULL;
    first_chara(fd, &chara, &len);
    if (fd == -1 || chara == 0) {
        len = 0;
        return NULL;
    }
    for (; chara != '\n' && chara != '\0'; i++) {
        res[i] = chara;
        res[i + 1] = '\0';
        first_chara(fd, &chara, &len) == 1 ? nb_rep++ : 0;
        cond_main(&res, nb_rep);
    }
    return (last_res(res, &nb_rep, &len, i));
}
