#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - prints strings separated by a given string
 * @separator: string to print between elements
 * @n: number of strings passed
 *
 * Description: Prints (nil) for NULL strings.
 * If separator is NULL, it is not printed.
 * Prints a new line at the end.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char *sep = "";

	va_start(args, n);

	while (i < n)
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(nil)";
		printf("%s%s", sep, str);
		sep = separator != NULL ? (char *)separator : "";
		i++;
	}

	va_end(args);
	printf("\n");
}
