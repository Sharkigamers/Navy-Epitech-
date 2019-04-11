/*
** EPITECH PROJECT, 2019
** navy
** File description:
** connection
*/

#include "my.h"

void successful_connection(int i, siginfo_t *pit, void *v)
{
    i = i;
    v = v;
    my_printf("enemy connected\n\n");
    stock = pit->si_pid;
}

void successful_enemy_connection(char *av, fpb_t *fpb)
{
    fpb->player1 = my_atoi(av);
    fpb->player2 = getpid();
    my_printf("my_pid:  %d\nsuccessfully connected\n\n", getpid());
    kill(fpb->player1, SIGUSR1);
}

void wait_for_enemy(fpb_t *fpb)
{
    struct sigaction s;

    fpb->player1 = getpid();
    my_printf("my_pid:  %d\nwaiting for enemy connection...\n\n",
            fpb->player1);
    sigemptyset(&s.sa_mask);
    s.sa_sigaction = &successful_connection;
    s.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &s, NULL);
    pause();
}

int second_player_connection(char **av, fpb_t *fpb, gest_t *gest)
{
    if (first_player_ship(av[2], gest, fpb) == 84)
        return (84);
    successful_enemy_connection(av[1], fpb);
    print_first_player_map(fpb);
    my_printf("waiting for enemy's attack...\n");
    return (0);
}

int first_player_connection(char **av, fpb_t *fpb, gest_t *gest)
{
    if (first_player_ship(av[1], gest, fpb) == 84)
        return (84);
    wait_for_enemy(fpb);
    fpb->player2 = stock;
    print_first_player_map(fpb);
    signal(SIGUSR1, 0);
    return (0);
}
