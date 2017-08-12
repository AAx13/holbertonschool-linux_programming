#include "signals.h"

/**
 * signal_handler - prints the captured signal information to stdout.
 * @sig: A signal number.
 * @info: Signal info struct.
 * @context: Pointer to context.
 *
 * Return: Void.
 */
void signal_handler(int sig __attribute__((unused)), siginfo_t *info,
		    void *context __attribute__((unused)))
{
	psiginfo(info, "Caught");
	fflush(stdout);
}

/**
 * all_in_one - sets up a single handler for all the signals.
 *
 * Return: Void.
 */
void all_in_one(void)
{
	struct sigaction sa;
	int i;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	for (i = 0; i < 32; i++)
	{
		sigaction(i, &sa, NULL);
	}
}
