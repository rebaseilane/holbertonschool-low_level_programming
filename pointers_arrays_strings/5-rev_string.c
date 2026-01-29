#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int start = 0;
	int end = 0;
	char temp;

	/* Find the length of the string */
	while (s[end] != '\0')
		end++;

	end--; /* move to last character */

	/* Swap characters from both ends */
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		start++;
		end--;
	}
}
