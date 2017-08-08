#include "signals.h"

/**
 * print_sender_pid - prints the pid of the last signal sender.
 * @sig: Signal number.
 * @info: Signal info struct to get sender process ID from.
 * @context: Pointer to context.
 *
 * Return: Void.
 */
void print_sender_pid(int sig __attribute__((unused)), siginfo_t *info,
		      void *context __attribute__((unused)))
{
	printf("SIGQUIT sent by %d\n", info->si_pid);
}

/**
 * trace_signal_sender - defines a handler for the signal SIGQUIT.
 *
 * Return: 0 on success or -1 on failure.
 */
int trace_signal_sender(void)
{
	struct sigaction sa;

	sa.sa_sigaction = print_sender_pid;
	if (sigaction(SIGQUIT, &sa, NULL) != 0)
	{
		return (-1);
	}

	return (0);
}
