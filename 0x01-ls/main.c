#include "header.h"

/**
 * main - mainfile.
 * @ac: Amount of args.
 * @av: Args.
 *
 * Return: 0 if Ok, 1 if minor problems, 2 if serious trouble.
 */
int main(int ac, char **av __attribute__((unused)))
{
	if (ac == 1)
	{
		print_cwd();
		return (EXIT_SUCCESS);
	}

	return (EXIT_SUCCESS);
}
