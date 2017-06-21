#include "header.h"

/**
 * main - mainfile.
 * @ac: Amount of args.
 * @av: Args.
 *
 * Return: 0 if Ok, 1 if minor problems, 2 if serious trouble.
 */
int main(int ac, char **av)
{
	dirlist *head;

	head = NULL;
	if (ac == 1)
	{
		print_cwd();
		return (EXIT_SUCCESS);
	}
	else
	{
		av++;
		while (*av)
		{
			process_arg(&head, *av);
			av++;
		}
	}
	print_list(head);
	delete_list(head);

	return (EXIT_SUCCESS);
}
