/*
** EPITECH PROJECT, 2019
** navy
** File description:
** chose attack
*/

#include "my.h"

int check_value(char *line)
{
    if ((my_strlen(line) != 2) || ((line[0] < 'A' || line[0] > 'H') ||
                                    (line[1] < '1' || line[1] > '8')))
        return (84);
    return (0);
}

void send_attack(char *line, pid_t pid)
{
    for (int i = line[0] - 64; i > 0; i--) {
        kill(pid, SIGUSR1);
        usleep(300);
    }
    kill(pid, SIGUSR2);
    for (int i = line[1] - 48; i > 0; i--) {
        kill(pid, SIGUSR1);
        usleep(300);
    }
    kill(pid, SIGUSR2);
}

int annex_main_cond(int ac, char *line, fpb_t *fpb)
{
    if (ac == 3) {
        send_attack(line, fpb->player1);
        while (receive_touch_signal(fpb, line) == 0);
        my_printf("\n");
        print_first_player_map(fpb);
        my_printf("waiting for enemy's attack...\n");
    }
    return (0);
}

int main_cond(int ac, char *line, fpb_t *fpb)
{
    if (ac == 2) {
        send_attack(line, fpb->player2);
        while (receive_touch_signal(fpb, line) == 0);
        my_printf("\nwaiting for enemy's attack...\n");
    }
    return (annex_main_cond(ac, line, fpb));
}

int player_attack(fpb_t *fpb, int ac)
{
    char *line = NULL;

    while (1) {
        my_printf("attack:\t");
        if ((line = get_next_line(0)) == NULL)
            continue;
        if (check_value(line) == 0) {
            return (main_cond(ac, line, fpb));
        } else
            my_printf("wrong position\n");
    }
    return (0);
}
