#include "../headers/holberton.h"

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
