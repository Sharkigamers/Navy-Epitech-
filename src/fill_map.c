/*
** EPITECH PROJECT, 2019
** navy
** File description:
** fill maps
*/

#include "my.h"

void init_struct(gest_t *gest)
{
    gest->ship1 = 0;
    gest->ship2 = 0;
    gest->ship3 = 0;
    gest->ship4 = 0;
    gest->check_board = malloc(sizeof(char *) * (12 + 1));
}

void fill_first_player_maps(fpb_t *fpb)
{
    fpb->my_board = malloc(sizeof(char *) * (8 + 1));
    fpb->enemi_board = malloc(sizeof(char *) * (8 + 1));
    for (int i = 0; i < 8; i++) {
        fpb->my_board[i] = malloc(sizeof(char) * (8 + 1));
        fpb->enemi_board[i] = malloc(sizeof(char *) * (8 + 1));
        for (int j = 0; j < 8; j++) {
            fpb->my_board[i][j] = '.';
            fpb->enemi_board[i][j] = '.';
        }
        fpb->my_board[i][8] = '\0';
        fpb->enemi_board[i][8] = '\0';
    }
    fpb->my_board[8] = NULL;
    fpb->enemi_board[8] = NULL;
}

void chang_enemy_board(fpb_t *fpb, char *lol)
{
    if (fpb->my_board[lol[1] - 49][lol[0] - 49] != '.')
        fpb->my_board[lol[1] - 49][lol[0] - 49] = 'x';
    fpb->enemi_board[lol[1] - 49][lol[0] - 49] = 'o';
}

int check_collision_board(fpb_t *fpb)
{
    int nb2 = 0;
    int nb3 = 0;
    int nb4 = 0;
    int nb5 = 0;

    for (int i = 0; fpb->my_board[i] != NULL; i++) {
        for (int j = 0; fpb->my_board[i][j] != '\0'; j++) {
            fpb->my_board[i][j] == '2' ? nb2++ : 0;
            fpb->my_board[i][j] == '3' ? nb3++ : 0;
            fpb->my_board[i][j] == '4' ? nb4++ : 0;
            fpb->my_board[i][j] == '5' ? nb5++ : 0;
        }
    }
    if (nb2 != 2 || nb3 != 3 || nb4 != 4 || nb5 != 5)
        return (84);
    return (0);
}
