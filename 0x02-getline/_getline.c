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
	char *line_read, *line_out;
	size_t count;
	char c;
	int i;

	i = 0;
	line_out = NULL;
	line_read = malloc(sizeof(char) * BUFFER);
	if (!line_read)
	{
		perror("line_read");
		return (NULL);
	}

	count = read(fd, &c, READ_SIZE);
	while (count)
	{
		if ((int)count == -1)
		{
			free(line_read);
			return (NULL);
		}

		if (count == 0 || c == '\n')
		{
			line_read[i] = '\0';
			line_out = truncate_line(line_read);

			free(line_read);
			return (line_out);
		}
		line_read[i] = c;
		count = read(fd, &c, READ_SIZE);
		i++;
	}

	free(line_read);
	return (NULL);
}
