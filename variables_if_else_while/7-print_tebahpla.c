#include <stdio.h>

/**
 * main - prints the lowercase alphabet in reverse
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c;

	for (c = 'z'; c >= 'a'; c--)
		putchar(c); /* First putchar prints letters from z to a */

	putchar('\n'); /* Second putchar prints the newline */

	return (0);
}
