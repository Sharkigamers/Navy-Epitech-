/*
** EPITECH PROJECT, 2019
** navy
** File description:
** gest error
*/

#include "my.h"

int check_numbers_and_chars(gest_t *gest, int i)
{
    if (gest->check_board[i][0] == gest->check_board[i + 1][0] &&
        gest->check_board[i][1] != gest->check_board[i + 1][1]) {
        if ((my_sqrt(my_pow((gest->check_board[i][1] - 48) -
            (gest->check_board[i + 1][1] - 48), 2)) + 1) !=
            (gest->check_board[i - 1][0] - 48))
            return (84);
    } else {
        if ((my_sqrt(my_pow((gest->check_board[i][0] - 64) -
            (gest->check_board[i + 1][0] - 64), 2)) + 1) !=
            (gest->check_board[i - 1][0] - 48))
            return (84);
    }
    return (0);
}

int in_pos_ships(gest_t *gest)
{
    int i;

    for (i = 1; i < 12; i += 3) {
        if ((gest->check_board[i][0] != gest->check_board[i + 1][0] &&
            gest->check_board[i][1] != gest->check_board[i + 1][1]) ||
            my_strcmp(gest->check_board[i], gest->check_board[i + 1]) == 0)
            return (84);
        if (check_numbers_and_chars(gest, i) == 84)
            return (84);
    }
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (j == i)
                continue;
            if (my_strcmp(gest->check_board[i], gest->check_board[j]) == 0)
                return (84);
        }
    }
    return (0);
}

int check_pos_ships(gest_t *gest, char *line, int *i)
{
    int j = 0;
    int k = 0;

    if (line[2] < 'A' || line[2] > 'H' || line[5] < 'A' || line[5] > 'H') {
        write(2, "You can't place ship under A and above H of size\n", 49);
        return (84);
    }
    if (line[1] != ':' || line[4] != ':') {
        write(2, "Error: Syntax: nb:'letter'nb:'letter'nb\n", 40);
        return (84);
    }
    for (int l = 0; l < 3; l++, (*i)++) {
        gest->check_board[*i] = malloc(30);
        for (k = 0; line[j] != ':' && line[j] != '\0'; j++, k++)
            gest->check_board[*i][k] = line[j];
        j++;
        gest->check_board[*i][k] = '\0';
    }
    return (0);
}

int check_ships(gest_t *gest, char *line)
{
    if (line[0] < '2' || line[0] > '5') {
        write(2, "You can't place ship under 2 and above 5 of size\n", 49);
        return (84);
    }
    if (line[0] == '2')
        gest->ship1++;
    if (line[0] == '3')
        gest->ship2++;
    if (line[0] == '4')
        gest->ship3++;
    if (line[0] == '5')
        gest->ship4++;
    if (gest->ship1 > 1 || gest->ship2 > 1 ||
        gest->ship3 > 1 || gest->ship4 > 1) {
        write(2, "CHEATER ! YOU TRIED TO PLACE SAME SHIP 2 TIMES\n", 47);
        return (84);
    }
    return (0);
}

int gest_error(char *line, gest_t *gest, int *i)
{
    if (my_strlen(line) != 7) {
        write(2, "Error: In line: > or < to 7 character\n", 38);
        return (84);
    }
    if (line[0] < '0' || line[0] > '9' || line[3] < '0' || line[3] > '9' ||
        line[6] < '0' || line[6] > '9') {
        write(2, "Error: Positions: nb:'letter'nb:'letter'nb\n", 43);
        return (84);
    }
    if (check_ships(gest, line) == 84 || check_pos_ships(gest, line, i) == 84)
        return (84);
    return (0);
}
