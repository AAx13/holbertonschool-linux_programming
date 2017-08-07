#include "signals.h"

/**
 * current_handler_signal - retrieves the current handler of the signal SIGINT.
 *
 * Return: Void.
 */
void (*current_handler_signal(void))(int)
{
	void (*old_handler_signal)(int) = NULL;

	old_handler_signal = signal(SIGINT, print_hello);
	if (old_handler_signal == SIG_ERR)
	{
		return (NULL);
	}

	return (old_handler_signal);
}
