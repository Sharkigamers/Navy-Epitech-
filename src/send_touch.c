/*
** EPITECH PROJECT, 2019
** send_touch.c
** File description:
** send my touch or not signal
*/

#include "my.h"

int send_touch_signal(fpb_t *fpb, char *received, pid_t pid)
{
    if (modif_map(fpb, received) == 0) {
        kill(pid, SIGUSR2);
        usleep(300);
        kill(pid, SIGUSR1);
        return (0);
    }
    else {
        kill(pid, SIGUSR2);
        usleep(300);
        kill(pid, SIGUSR2);
        usleep(300);
        kill(pid, SIGUSR1);
        return (0);
    }
}

void stock_touch(int num)
{
    num = num;
    wrapthree(1, 1);
}

void stock_end(int num)
{
    num = num;
    wrap(1, 1);
}

int receive_touch_signal(fpb_t *fpb, char *line)
{
    signal(SIGUSR2, stock_touch);
    signal(SIGUSR1, stock_end);
    while (wrap(1, 0) != 1);
    if (wrapthree(0, 0) == 1) {
        fpb->enemi_board[line[1] - 49][line[0] - 65] = 'o';
        my_printf("%s: missed\n", line);
        wrapthree(0, 1);
        wrap(0, 1);
        return (1);
    }
    else if (wrapthree(0, 0) == 2) {
        fpb->enemi_board[line[1] - 49][line[0] - 65] = 'x';
        my_printf("%s: hit\n", line);
        wrapthree(0, 1);
        wrap(0, 1);
        return (1);
    }
    return (0);
}
