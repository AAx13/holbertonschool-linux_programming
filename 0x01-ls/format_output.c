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

	if (args == 0)
	{
		printf("list current directory contents\n");
	}

	if (args == 1)
	{
		printf("check for options and list contents of directory\n");
	}

	if (args > 1)
	{
		printf("check for options and format for two or more lists of directory contents\n");
	}

	return (0);
}
