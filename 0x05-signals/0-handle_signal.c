#include "signals.h"

/**
 * print_sig - prints a signal number.
 * @sig: A signal number.
 *
 * Return: Void.
 */
void print_sig(int sig)
{
	printf("Gotcha! [%d] \n", sig);
}

/**
 * handle_signal - set a handler for the signal SIGINT.
 *
 * Return: 0 if successful or -1 on failure.
 */
int handle_signal(void)
{
	signal(SIGINT, print_sig);
	if (errno)
	{
		return (-1);
	}

	return (0);
}
