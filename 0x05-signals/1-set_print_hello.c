#include "signals.h"

/**
 * print_hello - prints some text when SIGINT signal is received.
 * @sig: Signal number.
 *
 * Return: Void.
 */
void print_hello(int sig __attribute__((unused)))
{
	printf("Hello :)\n");
	fflush(stdout);
}

/**
 * set_print_hello - sets a handler for SIGINT.
 *
 * Return: Void.
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
