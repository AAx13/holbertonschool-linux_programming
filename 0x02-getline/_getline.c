#include "_getline.h"

/**
 * _getline - reads an entire line from a file descriptor.
 * @fd: A file descriptor.
 *
 * Return: Null terminated string that does not include newline.
 * NULL on error.
 */
char *_getline(const int fd)
{
	size_t count;
	char *line;

	line = malloc(sizeof(char) * READ_SIZE);
	if (!line)
	{
		perror("line");
		return (NULL);
	}

	count = read(fd, line, (size_t)READ_SIZE);
	if (count == 0)
	{
		return (NULL);
	}

	return (line);
}
