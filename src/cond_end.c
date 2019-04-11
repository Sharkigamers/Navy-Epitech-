/*
** EPITECH PROJECT, 2019
** navy
** File description:
** cond end
*/

#include "my.h"

int end_cond(fpb_t *fpb)
{
    int ship = 0;

    for (int i = 0; fpb->my_board[i] != NULL; i++) {
        for (int j = 0; fpb->my_board[i][j] != '\0'; j++)
            fpb->my_board[i][j] >= '2' &&
                fpb->my_board[i][j] <= '5' ? ship++ : 0;
    }
    if (ship == 0) {
        print_first_player_map(fpb);
        my_printf("Enemy won\n");
        return (1);
    }
    return (0);
}

int end_sec_cond(fpb_t *fpb)
{
    int ship = 0;

    for (int i = 0; fpb->enemi_board[i] != NULL; i++) {
        for (int j = 0; fpb->enemi_board[i][j] != '\0'; j++)
            fpb->enemi_board[i][j] == 'x' ? ship++ : 0;
    }
    if (ship == 14) {
        print_first_player_map(fpb);
        my_printf("I won\n");
        return (0);
    }
    return (1);
}
