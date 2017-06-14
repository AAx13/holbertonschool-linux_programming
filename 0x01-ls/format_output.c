#include "header.h"

int format_output(char **av)
{
	int i, args;

	i = 1;
	args = 0;
	while (av[i])
	{
		if (strncmp(av[i], "-", 1) != 0)
		{
			args++;
		}
		i++;
	}

	switch (args)
	{
		case 0:
			printf("list current directory contents\n");
			break;

		case 1:
			printf("check for options and list contents of directory\n");
			break;

		default:
			printf("check for options and format for two or more lists of directory contents\n");
	}

	return (0);
}
