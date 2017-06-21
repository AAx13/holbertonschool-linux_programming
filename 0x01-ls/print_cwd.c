#include "header.h"

/**
 * print_cwd - print contents of current working directory.
 *
 * Return: 0 on success, otherwise 1.
 */
int print_cwd(void)
{
	struct dirent *read;
	DIR *dirp;

	dirp = opendir(".");

	read = readdir(dirp);
	while (read)
	{
		if (_strncmp(read->d_name, ".", 1) != 0)
		{
			printf("%s  ", read->d_name);
		}
		read = readdir(dirp);
	}
	printf("\n");

	return (EXIT_SUCCESS);
}
