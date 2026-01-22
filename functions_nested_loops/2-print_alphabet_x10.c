#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet in lowercase 10 times
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	char c;
	int i;

	for (i = 0; i < 10; i++)   /* outer loop for 10 lines */
	{
		for (c = 'a'; c <= 'z'; c++)  /* inner loop prints a-z */
			_putchar(c);
		_putchar('\n');   /* newline after each alphabet */
	}
}
