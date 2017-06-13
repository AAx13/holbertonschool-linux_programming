#include "header.h"

/**
 * process_opt - determines where options should be sent.
 * @av: Array of strings containing args.
 *
 * Return: Void.
 */
void process_opt(char **av)
{
	while (**av)
	{
		switch (**av)
		{
			case '1':
				printf("-1 flag\n");
				break;

			case 'a':
				printf("-a flag\n");
				break;

			case 'A':
				printf("-A flag\n");
				break;

			case 'l':
				printf("-l flag\n");
				break;
		}
		(*av)++;
	}
}
