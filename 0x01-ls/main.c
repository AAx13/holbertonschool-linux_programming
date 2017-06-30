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
	int id;
	dirlist *head;
	int dir, file, process_ret;

	id = 1;
	dir = 0;
	file = 0;
	head = NULL;
	if (ac == 1)
	{
		process_arg(&head, ".", id);
		dir++;
	}
	else
	{
		av++;
		while (*av)
		{
			process_ret = process_arg(&head, *av, id);
			if (process_ret == 0)
			{
				dir++;
			}
			else if (process_ret == 1)
			{
				file++;
			}
			av++;
			id++;
		}
	}
	sort_list(head, dir, file);
	print_list(head, dir, file);
	delete_list(head);

	return (EXIT_SUCCESS);
}
