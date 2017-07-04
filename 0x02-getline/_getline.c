#include "_getline.h"

/**
 * truncate_line - breaks off correct line to be returned.
 * @line_read: Original line to be truncated.
 *
 * Return: Truncated string or NULL if error allocating memory.
 */
char *truncate_line(char *line_read)
{
	char *line_out;
	size_t len;

	len = _strlen(line_read) + 1;
	line_out = malloc(sizeof(char) * len);
	if (!line_out)
	{
		perror("line_out");
		return (NULL);
	}

	strncpy(line_out, line_read, len);

	return (line_out);

}

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
	line_read = malloc(sizeof(char) * 1024);
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
