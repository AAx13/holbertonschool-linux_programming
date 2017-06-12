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
	struct dirent *dirent;
	DIR *dirp;

	av++;
	while (*av != NULL)
	{
		if ((dirp = opendir(*av)) == NULL)
		{
			perror(*av);
			exit(EXIT_FAILURE);
		}

		while ((dirent = readdir(dirp)))
		{
			if (strncmp(dirent->d_name, ".", 1) != 0)
			{
				printf("%s  ", dirent->d_name);
			}
		}
		printf("\n");

		av++;
	}

	return (EXIT_SUCCESS);
}
