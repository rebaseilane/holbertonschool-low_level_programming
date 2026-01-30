#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: pointer to the string
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i;
	int j;
	char sep[] = " \t\n,;.!?\"(){}";

	i = 0;

	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}

		j = 0;
		while (sep[j] != '\0')
		{
			if (str[i - 1] == sep[j] &&
			    str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 32;
			}
			j++;
		}
		i++;
	}

	return (str);
}
