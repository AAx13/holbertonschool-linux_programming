#include "header.h"

/**
 * process_arg - send arg info to their respective structs.
 * @head: A linked list.
 * @arg: An arg from stdin.
 * @id: Used to identify each arg group.
 *
 * Return: 0 if dir, 1 if file, 2 if option. -1 if there was an issue.
 */
int process_arg(dirlist **head, char *arg, int id)
{
	struct stat sb;

	if (lstat(arg, &sb) == -1)
	{
		if (_strncmp(arg, "-", 1) == 0)
		{
			printf("option\n");
			return (2);
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
			build_list(head, arg, 0, id);
			return (0);

		case S_IFREG:
			build_list(head, arg, 1, id);
			return (1);
	}

	return (-1);
}
