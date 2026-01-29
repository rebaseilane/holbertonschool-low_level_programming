#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: the integer converted from the string
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;

	/* Handle all signs before the number */
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '+' || s[i] == '-'))
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	/* Convert digits to integer */
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (result * sign);
}
