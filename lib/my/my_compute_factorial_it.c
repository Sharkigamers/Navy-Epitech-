/*
** EPITECH PROJECT, 2018
** my_sqrt
** File description:
** sqrt in math
*/

int my_pow(int nb, int p);

int my_sqrt(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    if (nb == 1)
        return (1);
    for (int i = 0; i < nb; i++)
        if (my_pow(i, 2) == nb)
            return (i);
    return (0);
}
