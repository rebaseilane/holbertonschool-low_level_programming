#include "main.h"

/**
 * _puts_recursion - prints a string followed by a new line
 * @s: the string to print
 *
 * Description: This function prints each character of the string
 *              using recursion and finally prints a new line.
 */
void _puts_recursion(char *s)
{
	if (*s == '\0') /* Base case: end of string */
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);           /* Print first character */
	_puts_recursion(s + 1); /* Recursive call for the rest of the string */
}
