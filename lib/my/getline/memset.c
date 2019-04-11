/*
** EPITECH PROJECT, 2019
** memset
** File description:
** make the memset
*/

char *my_memset(char *res, char c, int size)
{
    for (int  i =0; i != size; i++)
        res[i] = c;
    return (res);
}
