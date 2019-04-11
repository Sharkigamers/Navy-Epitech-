/*
** EPITECH PROJECT, 2019
** navy
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void print_flag_h(void)
{
    int fd = open("READ_ME", O_RDONLY);
    char *res = NULL;

    while ((res = get_next_line(fd)) != NULL)
        my_printf("%s\n", res);
    close(fd);
}

int main(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_flag_h();
        return (0);
    }
    return (navy(ac, av));
}
