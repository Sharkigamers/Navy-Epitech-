/*
** EPITECH PROJECT, 2018
** my_pow
** File description:
** compute power by recursivity
*/

int my_pow(int nb, int p)
{
    int final_number = nb;

    if (p < 0)
        return(0);
    if (p == 0)
        return (1);
    else {
        final_number = nb * my_pow(nb, p -= 1);
    }
    return (final_number);
}
