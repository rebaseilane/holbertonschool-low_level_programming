#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	/* Move i to the end of dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Copy src into dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add final null byte */
	dest[i] = '\0';

	return (dest);
}
