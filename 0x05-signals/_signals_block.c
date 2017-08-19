#include "signals.h"

/**
 * _signals_block - blocks a given set of signals
 * from being delivered to the current process.
 * @signals: A NULL (0) terminated array of int,
 * each one being a signal to block.
 *
 * Return: 0 on success, or -1 on error.
 */
int _signals_block(int *signals)
{
	sigset_t set;

	sigemptyset(&set);
	while (*signals)
	{
		if (sigaddset(&set, *signals) != 0)
		{
			return (-1);
		}
		signals++;
	}

	if (sigprocmask(SIG_BLOCK, &set, NULL) != 0)
	{
		return (-1);
	}

	return (0);
}
