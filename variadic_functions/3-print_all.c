#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

typedef struct printer
{
	char *symbol;
	void (*print)(va_list);
} printer_t;

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

void print_string(va_list args)
{
	char *str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints anything based on a format string
 * @format: list of types of arguments passed ('c', 'i', 'f', 's')
 *
 * Description: Prints char, int, float, or string arguments.
 * Other characters are ignored. Each element is separated by ", ".
 * Prints a new line at the end.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j;
	char *sep = "";
	printer_t printers[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(args, format);

	if (format != NULL)
		while (format[i])
		{
			j = 0;
			while (printers[j].symbol != NULL)
			{
				if (format[i] == *(printers[j].symbol))
				{
					printf("%s", sep);
					printers[j].print(args);
					sep = ", ";
				}
				j++;
			}
			i++;
		}

	va_end(args);
	printf("\n");
}
