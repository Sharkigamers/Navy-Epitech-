/*
** EPITECH PROJECT, 2019
** navy
** File description:
** print the maps
*/

#include "my.h"

void print_first_player_map(fpb_t *fpb)
{
    my_printf("my positions:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 1; fpb->my_board[i - 1] != NULL; i++) {
        my_printf("%d|", i);
        for (int j = 0; j < 8; j++) {
            my_printf("%c", fpb->my_board[i - 1][j]);
            j != 7 ? my_printf(" ") : 0;
        }
        my_printf("\n");
    }
    my_printf("\nenemy's positions:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 1; fpb->my_board[i - 1] != NULL; i++) {
        my_printf("%d|", i);
        for (int j = 0; j < 8; j++) {
            my_printf("%c", fpb->enemi_board[i - 1][j]);
            j != 7 ? my_printf(" ") : 0;
        }
        my_printf("\n");
    }
    my_printf("\n");
}
