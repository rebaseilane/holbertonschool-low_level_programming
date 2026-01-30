#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: pointer to the modified string
 */
char *leet(char *s)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	i = 0;
	while (s[i] != '\0')   /* first loop: go through the string */
	{
		j = 0;
		while (letters[j] != '\0')  /* second loop: check letters to replace */
		{
			if (s[i] == letters[j])  /* only one if allowed */
			{
				s[i] = numbers[j];
			}
			j++;
		}
		i++;
	}
	return (s);
}
