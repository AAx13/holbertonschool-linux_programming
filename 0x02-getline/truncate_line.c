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
