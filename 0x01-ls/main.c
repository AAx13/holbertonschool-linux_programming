#include "header.h"

/**
 * main - mainfile.
 * @ac: Amount of args.
 * @av: Array of strings containing args.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int ac __attribute__((unused)), char **av)
{
	av++;
	if (!*av)
	{
		printf("current directory ( )\n");
	}

	while (*av)
	{
		switch (**av)
		{
			case '.':
				printf("current directory (.)\n");
				break;

			case '-':
				process_opt(av);
				break;

			default:
				printf("operate on this directory %s\n", *av);
		}
		av++;
	}

	return (EXIT_SUCCESS);
}
