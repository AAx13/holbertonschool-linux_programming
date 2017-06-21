#include "header.h"

/**
 * print_error - prints error based on errno.
 * @arg: An argument from stdin.
 *
 * Return: 1 if minor problem, 2 if serious trouble, or -1
 * if error code not recognized.
 */
int print_error(char *arg)
{
	switch (errno)
	{
		case 2:
			printf("hls: cannot access %s: ", arg);
			printf("No such file or directory\n");
			return (2);

		case 13:
			printf("hls: cannot open directory %s: ", arg);
			printf("Permission denied\n");
			return (2);
	}
	return (-1);
}
