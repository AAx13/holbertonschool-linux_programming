#include <unistd.h>

/**
 * _putchar - writes a character to stdout.
 * @c: A character.
 *
 * Return: Bytes written to stdout.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
