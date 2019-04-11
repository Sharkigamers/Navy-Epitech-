/*
** EPITECH PROJECT, 2019
** navy
** File description:
** modif the map
*/

#include "my.h"

int modif_map(fpb_t *fpb, char *received)
{
    int nb_received = my_atoi(received);

    if (fpb->my_board[nb_received % 10 - 1][nb_received / 10 - 1] == '.' ||
        fpb->my_board[nb_received % 10 - 1][nb_received / 10 - 1] == 'x' ||
        fpb->my_board[nb_received % 10 - 1][nb_received / 10 - 1] == 'o') {
        fpb->my_board[nb_received % 10 - 1][nb_received / 10 - 1] = 'o';
        my_printf("%c%c: missed\n\n",
                    nb_received / 10 + 64, nb_received % 10 + 48);
        return (0);
    }
    else {
        fpb->my_board[nb_received % 10 - 1][nb_received / 10 - 1] = 'x';
        my_printf("%c%c: hit\n\n",
                    nb_received / 10 + 64, nb_received % 10 + 48);
        return (1);
    }
}
