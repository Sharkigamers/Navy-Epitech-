/*
** EPITECH PROJECT, 2019
** navy
** File description:
** init positions of ships
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int check_first_error(char *av, gest_t *gest)
{
    int fd = open(av, O_RDONLY);
    char *line = NULL;
    int i = 0;
    int k;

    if (fd == -1)
        return (84);
    init_struct(gest);
    for (k = 0; (line = get_next_line(fd)) != NULL;) {
        if (gest_error(line, gest, &i) == 84)
            return (84);
        my_strcmp(line, "") != 0 ? k++ : 0;
    }
    if (k < 4)
        return (84);
    gest->check_board[12] = NULL;
    if (in_pos_ships(gest) == 84)
        return (84);
    close(fd);
    return (0);
}

void fill_of_ships(gest_t *gest, fpb_t *fpb, int i)
{
    int l;

    if (gest->check_board[i][0] == gest->check_board[i + 1][0] &&
        gest->check_board[i][1] != gest->check_board[i + 1][1]) {
        l = gest->check_board[i][1] - 48;
        for (int k = (gest->check_board[i][1] - 48); k <=
            (gest->check_board[i + 1][1] - 48); k++, l++) {
            fpb->my_board[l - 1][gest->check_board[i][0] - 64 - 1] =
                gest->check_board[i - 1][0];
        }
    }
    else {
        l = gest->check_board[i][0] - 64;
        for (int k = (gest->check_board[i][0] - 64); k <=
            (gest->check_board[i + 1][0] - 64); k++, l++) {
            fpb->my_board[gest->check_board[i][1] - 48 - 1][l - 1] =
                gest->check_board[i - 1][0];
        }
    }
}

void fill_map(gest_t *gest, fpb_t *fpb)
{
    int i;

    for (i = 1; i < 12; i += 3) {
        if (my_strcmp(gest->check_board[i], gest->check_board[i + 1]) == 1)
            swap(&gest->check_board[i], &gest->check_board[i + 1]);
        fill_of_ships(gest, fpb, i);
    }
}

int first_player_ship(char *av, gest_t *gest, fpb_t *fpb)
{
    if (check_first_error(av, gest) == 84)
        return (84);
    fill_map(gest, fpb);
    if (check_collision_board(fpb) == 84)
        return (84);
    for (int i = 0; gest->check_board[i] != NULL; i++)
        free(gest->check_board[i]);
    free(gest->check_board);
    return (0);
}
