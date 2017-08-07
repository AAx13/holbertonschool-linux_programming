#include "signals.h"

/**
 * current_handler_sigaction - retrieves the current handler of the
 * signal SIGINT.
 *
 * Return: Void.
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction sa_action;

	if (sigaction(SIGINT, NULL, &sa_action) != 0)
	{
		return (NULL);
	}

	return (sa_action.sa_handler);
}
