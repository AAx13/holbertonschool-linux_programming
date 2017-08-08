#include "signals.h"

/**
 * main - prints a description of a given signal.
 * @ac: Amount of arguments.
 * @av: Array containing an argument per index (null terminated).
 *
 * Return: EXIT_SUCCES or EXIT_FAILURE.
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: %s <signum>\n", av[0]);
		exit(EXIT_FAILURE);
	}
	printf("%s: %s\n", av[1], strsignal(atoi(av[1])));

	return (EXIT_SUCCESS);
}
