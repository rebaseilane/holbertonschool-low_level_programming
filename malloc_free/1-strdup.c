#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated copy of a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if str is NULL
 *         or if memory allocation fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	/* Find the length of the string */
	len = 0;
	while (str[len] != '\0')
		len++;

	/* Allocate memory for the duplicate string */
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	/* Copy characters from original string to the new string */
	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
