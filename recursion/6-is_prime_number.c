#include "main.h"

/**
 * _is_prime_helper - checks recursively if n is divisible by i
 * @n: number to check
 * @i: current divisor
 *
 * Return: 1 if n is prime, 0 if not
 */
int _is_prime_helper(int n, int i)
{
	if (i >= n)
		return (1); /* reached n without finding a divisor */

	if (n % i == 0)
		return (0); /* divisible by i → not prime */

	return (_is_prime_helper(n, i + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, 0 if not
 * @n: number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0); /* 0 and 1 are not prime */

	return (_is_prime_helper(n, 2));
}
