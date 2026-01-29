#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: integer converted from string
 */
int _atoi(char *s)
{
	int i, sign, result, found_digit;

	i = 0;
	sign = 1;
	result = 0;
	found_digit = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			found_digit = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (found_digit)
			break;

		i++;
	}

	return (result * sign);
}
