/*
** EPITECH PROJECT, 2019
** receive attack
** File description:
** create my receive attack for my signals
*/

#include "my.h"

void handle_sig1(int num)
{
    if (wrap(22, 0) > stock) {
        wraptwo(wrap(22, 0), 1);
    }
    num = num;
    stock++;
    wrap(stock, 1);
}

void handle_sig2(int num)
{
    num = num;
    stock = 0;
    wrapthree(1, 1);
}

char *receive_attack(void)
{
    char *attack;

    signal(SIGUSR1, handle_sig1);
    signal(SIGUSR2, handle_sig2);
    if (wrapthree(22, 0) == 2) {
        attack = malloc(3);
        attack[0] = wraptwo(22, 0) + 48;
        attack[1] = wrap(22, 0) + 48;
        attack[2] = '\0';
        wrap(0, 1);
        wraptwo(0, 1);
        wrapthree(0, 1);
        return (attack);
    }
    return (NULL);
}
