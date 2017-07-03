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
	char c;
	int i;

	i = 0;
	if (!fd)
	{
		return (NULL);
	}

	line = malloc(sizeof(char) * 81);
	if (!line)
	{
		perror("line");
		return (NULL);
	}

	count = read(fd, &c, READ_SIZE);
	while (count)
	{
		if ((int)count == -1)
		{
			return (NULL);
		}

		if (count == 0 || c == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		line[i] = c;
		count = read(fd, &c, READ_SIZE);
		i++;
	}

	return (NULL);
}
