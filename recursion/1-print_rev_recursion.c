#include "main.h"

/**
 * _print_rev_recursion - prints a string in reverse
 * @s: the string to print
 *
 * Description: This function prints the string starting from the last
 *              character to the first using recursion.
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0') /* Base case: end of string */
		return;

	_print_rev_recursion(s + 1); /* Recursive call for rest of string */
	_putchar(*s);                /* Print character on stack unwinding */
}
