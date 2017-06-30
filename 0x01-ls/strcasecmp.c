#include "header.h"

/**
 * _strcasecmp - compare two strings ignoring case.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: An integer less than, equal to, or greater than zero.
 */
int _strcasecmp(const char *s1, const char *s2)
{
	const char *cpy1 = s1;
	const char *cpy2 = s2;

	char c1, c2;

	if (cpy1 == cpy2)
	{
		return (0);
	}

	do {
		c1 = _tolower(*cpy1);
		c2 = _tolower(*cpy2);
		cpy1++;
		cpy2++;

	} while (c1 && c1 == c2);

	return (c1 - c2);
}
