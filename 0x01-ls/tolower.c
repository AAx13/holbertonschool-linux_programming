#include "header.h"

/**
 * _tolower - convert letter to lower case.
 * @c: A character.
 *
 * Return: Converted character.
 */
int _tolower(int c)
{
	if (c > 64 && c < 91)
	{
		return (c + 32);
	}
	return (c);
}
