#include "signals.h"

/**
 * handle_pending - sets up a handler for all the pending
 * signals of the current process.
 * @handler: A pointer to the handler function to set for the pending signals.
 *
 * Return: 0 on success, -1 on error.
 */
int handle_pending(void (*handler)(int))
{
	struct sigaction sa;
	sigset_t pending_set;
	int i;

	sa.sa_handler = handler;
	sigpending(&pending_set);
	for (i = 0; i < 32; i++)
	{
		sigaction(i, &sa, NULL);
	}

	return (0);
}
