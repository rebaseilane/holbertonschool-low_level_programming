#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - prints strings separated by a string
 * @separator: string to print between strings
 * @n: number of strings passed to the function
 *
 * Description: If separator is NULL, it is not printed.
 * If a string is NULL, prints (nil) instead.
 * Prints a new line at the end.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);
		if (str == NULL)
			printf("(nil)");
		if (str != NULL)
			printf("%s", str);
		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	va_end(args);
	printf("\n");
}
