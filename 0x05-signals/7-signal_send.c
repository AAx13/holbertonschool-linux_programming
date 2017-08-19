#include "signals.h"

/**
 * main - sends the signal SIGINT to a process, given its PID.
 * @ac: Number of arguments.
 * @av: Array of arguments passed.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: %s <pid>\n", av[0]);
		return (EXIT_FAILURE);
	}
	kill(atoi(av[1]), SIGTERM);

	return (EXIT_SUCCESS);
}
