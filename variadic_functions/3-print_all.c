#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything
 * @format: list of argument types
 *
 * Description: c = char, i = int, f = float, s = char *.
 * If string is NULL, prints (nil).
 * Prints a new line at the end.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	char *sep = "";
	char c;

	va_start(args, format);

	while (format && format[i])
	{
		c = format[i];
		if (c == 'c' || c == 'i' || c == 'f' || c == 's')
		{
			printf("%s", sep);
			if (c == 'c')
				printf("%c", va_arg(args, int));
			if (c == 'i')
				printf("%d", va_arg(args, int));
			if (c == 'f')
				printf("%f", va_arg(args, double));
			if (c == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(nil)";
				printf("%s", str);
			}
			sep = ", ";
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
