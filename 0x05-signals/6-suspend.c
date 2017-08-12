#include "signals.h"

/**
 * handle_sig - prints some notification if SIGINT is caught.
 * @sig: Signal number.
 *
 * Return: Void.
 */
void handle_sig(int sig)
{
	printf("Caught %d\n", sig);
}

/**
 * set_sig - sets a handler for SIGINT.
 *
 * Return: 0 on success and -1 on failure.
 */
int set_sig(void)
{
	if (signal(SIGINT, handle_sig) != 0)
	{
		return (-1);
	}

	return (0);
}

/**
 * main - sets a handler for the signal SIGINT,
 * and exits right after the signal is received and handled.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(void)
{
	if (set_sig() != 0)
	{
		return (EXIT_FAILURE);
	}

	pause();
	printf("Signal received\n");
	fflush(stdout);

	return (EXIT_SUCCESS);
}
