#include "signals.h"

/**
 * sigint_handler - prints some text when SIGINT signal is received.
 * @sig: A signal number.
 *
 * Return: Void.
 */
void sigint_handler(int sig)
{
	printf("Gotcha! [%d]\n", sig);
	fflush(stdout);
}

/**
 * handle_sigaction - set a handler for the signal SIGINT.
 *
 * Return: 0 on success or -1 on failure.
 */
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = sigint_handler;
	if (sigaction(SIGINT, &sa, NULL) != 0)
	{
		return (-1);
	}

	return (0);
}
