#include "signals.h"

/**
 * sigset_init - initializes a sigset.
 * @set: A pointer to the signal set to initialize.
 * @signals: NULL (0) terminated array of signals.
 *
 * Return: 0 on success, -1 on error.
 */
int sigset_init(sigset_t *set, int *signals)
{
	sigemptyset(set);
	while (*signals)
	{
		if (sigaddset(set, *signals) != 0)
		{
			return (-1);
		}
		signals++;
	}
	return (0);
}
