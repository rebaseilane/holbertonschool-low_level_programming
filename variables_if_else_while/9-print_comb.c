#include <stdio.h>

/**
 * main - prints all single-digit numbers separated by ", "
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0'); /* Print the digit */
		if (i != 9)
		{
			putchar(',');  /* Print comma */
			putchar(' ');  /* Print space */
		}
	}
	putchar('\n'); /* Newline at the end */
	return (0);
}
