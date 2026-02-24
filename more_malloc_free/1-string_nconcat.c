#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 * @n: number of bytes to use from s2
 *
 * Return: pointer to newly allocated memory containing s1 followed
 * by the first n bytes of s2, or NULL if allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int len1;
	unsigned int len2;
	unsigned int i;
	unsigned int j;

	len1 = 0;
	len2 = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		n = len2;

	new_str = malloc(sizeof(char) * (len1 + n + 1));
	if (new_str == NULL)
		return (NULL);

	i = 0;
	while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}

	j = 0;
	while (j < n)
	{
		new_str[len1 + j] = s2[j];
		j++;
	}

	new_str[len1 + n] = '\0';

	return (new_str);
}
