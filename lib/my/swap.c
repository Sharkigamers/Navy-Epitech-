/*
** EPITECH PROJECT, 2019
** solostumper
** File description:
** swap
*/

void swap(char **s1, char **s2)
{
    char *s3;

    s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}
