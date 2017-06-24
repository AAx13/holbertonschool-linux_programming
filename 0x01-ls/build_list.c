#include "header.h"

/**
 * build_list - builds list containing information on a file or directory.
 * @head: A linked list.
 * @arg: Arg from stdin.
 * @i: Indicates if this is a file or directory.
 * @id: Used to identify each arg group.
 *
 * Return: Void.
 */
void build_list(dirlist **head, char *arg, int i, int id)
{
	struct dirent *read;
	DIR *dirp;

	if (i == 0)
	{
		dirp = opendir(arg);
		if (!dirp)
		{
			if (head)
			{
				delete_list(*head);
			}
			exit(print_error(arg));
		}

		read = readdir(dirp);
		if (!read)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		while (read)
		{
			if (read->d_type & DT_DIR)
			{
				add_to_list(head, arg, read->d_name, 0, id);
			}
			else
			{
				add_to_list(head, arg, read->d_name, 1, id);
			}
			read = readdir(dirp);
		}
		closedir(dirp);
	}
	else
	{
		add_to_list(head, arg, arg, 1, id);
	}
}
