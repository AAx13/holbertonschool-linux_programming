#include "../holberton.h"

/**
 * _strlen - calculate the length of a string.
 * @s: A string.
 *
 * Return: Length of the string excluding null terminator.
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}

	return (i);
}
