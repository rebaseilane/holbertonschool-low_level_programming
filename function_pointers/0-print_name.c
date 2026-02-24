#include <stddef.h>
#include "function_pointers.h"

/**
 * print_name - prints a name using a given function
 * @name: the name to print
 * @f: pointer to a function that takes a char* argument and returns void
 *
 * Description: This function calls the function pointed to by `f`
 * to print the name `name`.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
