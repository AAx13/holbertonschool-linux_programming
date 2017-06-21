#include "header.h"

/**
 * process_arg - send arg info to their respective structs.
 * @head: A linked list.
 * @arg: An arg from stdin.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int process_arg(dirlist **head, char *arg)
{
	struct stat sb;

	if (stat(arg, &sb) == -1)
	{
		if (_strncmp(arg, "-", 1) == 0)
		{
			printf("option\n");
			return (EXIT_SUCCESS);
		}
		else
		{
			if (head)
			{
				delete_list(*head);
			}
			exit(print_error(arg));
		}
	}

	switch (sb.st_mode & S_IFMT)
	{
		case S_IFDIR:
			build_list(head, arg, 0);
			break;

		case S_IFREG:
			build_list(head, arg, 1);
			break;
	}

	return (EXIT_SUCCESS);
}
