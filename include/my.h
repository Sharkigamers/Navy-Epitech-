/*
** EPITECH PROJECT, 2019
** navy
** File description:
** my
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#ifndef MY_
#define MY_

int stock;

typedef struct gest_error
{
    int ship1;
    int ship2;
    int ship3;
    int ship4;
    char **check_board;
} gest_t;

typedef struct first_player_board
{
    char **my_board;
    char **enemi_board;
    pid_t player1;
    pid_t player2;
} fpb_t;

/* lib */

void my_printf(char *fmt, ...);
char *get_next_line(int fd);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_sqrt(int nb);
int my_pow(int nb, int p);
void swap(char **s1, char **s2);
int my_putstr(char const *str);
int my_atoi(char *str);

/* navy */

int first_player_connection(char **av, fpb_t *fpb, gest_t *gest);
int second_player_connection(char **av, fpb_t *fpb, gest_t *gest);

/* signal */

char *receive_attack(void);
int send_touch_signal(fpb_t *fbp, char *res, pid_t pid);
int player_attack(fpb_t *fpb, int ac);
int receive_touch_signal(fpb_t *fpb, char *line);
int wrap(int i, int f);
int wraptwo(int i, int f);
int wrapthree(int i, int f);

/* map */

void fill_first_player_maps(fpb_t *fpb);
int modif_map(fpb_t *fpb, char *res);
void print_first_player_map(fpb_t *fpb);
int first_player_ship(char *av, gest_t *gest, fpb_t *fpb);

/* gest_error */

void init_struct(gest_t *gest);
int gest_error(char *line, gest_t *gest, int *i);
int in_pos_ships(gest_t *gest);
int check_collision_board(fpb_t *fpb);

/* end */

int end_cond(fpb_t *fpb);
int end_sec_cond(fpb_t *fpb);
int last_end_cond(fpb_t *fpb);

/* main */

int navy(int ac, char **av);

#endif
