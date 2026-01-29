#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the string to print
 *
 * Return: void
 */
void print_rev(char *s)
{
    int i = 0;

    /* Find the length of the string */
    while (s[i] != '\0')
        i++;

    /* Print the string in reverse */
    while (i > 0)
    {
        i--;
        _putchar(s[i]);
    }

    /* Print a newline at the end */
    _putchar('\n');
}
