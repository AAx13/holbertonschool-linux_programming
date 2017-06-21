#include "header.h"

/**
 * build_list - builds list containing information on a file or directory.
 * @head: A linked list.
 * @arg: The argument from stdin.
 * @i: Indicates if this arg is a file or directory.
 *
 * Return: Void.
 */
void build_list(dirlist **head, char *arg, int i)
{
	struct dirent *read;
	DIR *dirp;

	if (i == 0)
	{
		dirp = opendir(arg);
		if (!dirp)
		{
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
			add_to_list(head, read->d_name);
			read = readdir(dirp);
		}
		closedir(dirp);
	}
	else
	{
		printf("reserved for files\n");
	}
}
