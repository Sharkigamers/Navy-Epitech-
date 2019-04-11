/*
** EPITECH PROJECT, 2019
** navy
** File description:
** war ship
*/

#include "my.h"
#include <signal.h>
#include <stdlib.h>

int last_end_cond(fpb_t *fpb)
{
    if (end_cond(fpb) == 1)
        return (2);
    if (end_sec_cond(fpb) == 0)
        return (3);
    return (0);
}

int main_loop(int ac, fpb_t *fpb, char **res)
{
    if (ac == 2) {
        if (player_attack(fpb, ac) == 2)
            return (1);
        while ((*res = receive_attack()) == NULL);
        *res != NULL ? send_touch_signal(fpb, *res, fpb->player2) : 0;
        print_first_player_map(fpb);
    }
    if (ac == 3) {
        while ((*res = receive_attack()) == NULL);
        *res != NULL ? send_touch_signal(fpb, *res, fpb->player1) : 0;
        if (player_attack(fpb, ac) == 3)
            return (0);
    }
    return (2);
}

int navy(int ac, char **av)
{
    fpb_t fpb;
    gest_t gest;
    char *res = malloc(3);
    int nb;

    fill_first_player_maps(&fpb);
    if (ac == 2 && first_player_connection(av, &fpb, &gest) == 84)
        return (84);
    if (ac == 3 && second_player_connection(av, &fpb, &gest) == 84)
        return (84);
    stock = 0;
    while (1) {
        if ((nb = main_loop(ac, &fpb, &res)) != 2)
            return (nb);
    }
    return (0);
}
