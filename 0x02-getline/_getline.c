#include "_getline.h"

static int line_sentinel;
static char left_over[READ_SIZE];

/**
 * TODO:
 */

/**
 * _getline - reads an entire line from a file descriptor.
 * @fd: A file descriptor.
 *
 * Return: Null terminated string that does not include newline.
 * NULL on error.
 */
char *_getline(const int fd)
{
	char line_read[READ_SIZE + 1], *line_out = NULL;
	int byte_cnt;

	if (fd == -1)
	{
		line_sentinel = 0;
		memset(left_over, 0, READ_SIZE);
		return (NULL);
	}
	if (*left_over)
	{
		line_out = malloc(READ_SIZE + 1);
		memset(line_out, 0, READ_SIZE + 1);
		line_out = truncate_line(left_over, line_out);
		if (*left_over == '\n')
			memset(left_over, 0, READ_SIZE);

		if (line_sentinel == 1)
		{
			line_sentinel = 0;
			return (line_out);
		}
	}
	memset(left_over, 0, READ_SIZE + 1);
	do {
		memset(line_read, 0, READ_SIZE + 1);
		byte_cnt = read(fd, line_read, READ_SIZE);
		if (byte_cnt == 0 && line_out != NULL)
		{
			return (line_out);
		}
		line_out = setup_line(line_read, line_out);
		if (line_sentinel == 1)
		{
			line_sentinel = 0;
			return (line_out);
		}
	} while (byte_cnt);
	free(line_out);
	return (NULL);
}

/**
 * setup_line - allocate space and truncate line.
 * @line_read: The buffer read into.
 * @line_out: Line to return.
 *
 * Return: Line out.
 */
char *setup_line(char *line_read, char *line_out)
{
	int x;

	x = 0;
	if (line_out == NULL)
	{
		line_out = malloc(sizeof(char) * READ_SIZE + 1);
		memset(line_out, 0, READ_SIZE + 1);
	}
	else
	{
		x = _strlen(line_out);
		line_out = _realloc(line_out, x, x + READ_SIZE + 1);
	}
	line_out = truncate_line(line_read, line_out);

	return (line_out);
}

/**
 * truncate_line - truncate a line to be returned.
 * @line_in: Line to be truncated.
 * @line_out: Line to be returned to main function.
 *
 * Return: A truncated line suitable for immediate return to main function.
 */
char *truncate_line(char *line_in, char *line_out)
{
	int i, x;

	x = _strlen(line_out);
	for (i = 0; line_in[i]; i++, x++)
	{
		if (line_in[i] == '\n')
		{
			line_sentinel = 1;
			i++;
			break;
		}
		line_out[x] = line_in[i];
	}

	line_out[x] = '\0';

	if (line_in[i])
	{
		for (x = 0; line_in[i]; x++, i++)
		{
			left_over[x] = line_in[i];
		}
		left_over[x] = '\0';
	}

	return (line_out);
}

/**
 * _realloc - increase the size of the memory block pointed to by *ptr.
 * @ptr: Pointer to memory block to reallocate.
 * @old: Old size.
 * @new: New size.
 *
 * Return: Pointer to newly allocated space in memory.
 */
void *_realloc(void *ptr, size_t old, size_t new)
{
	void *new_ptr;

	new_ptr = NULL;
	if (new == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
	{
		new_ptr = malloc(new);
		return (new_ptr);
	}
	else if (new <= old)
	{
		return (ptr);
	}
	else
	{
		new_ptr = malloc(new);
		memset(new_ptr, 0, new);
		if (!new_ptr)
		{
			putstr("malloc->new_ptr\n");
			return (NULL);
		}
		memcpy(new_ptr, ptr, old);
		free(ptr);
	}

	return (new_ptr);
}

/**
 * putstr - writes a string to stdout.
 * @str: A string to write to stdout.
 *
 * Return: Bytes written. 0 if failed.
 */
int putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		return (0);
	}

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}

/**
 * _strlen - returns length of a string excluding null byte.
 * @str: A string.
 *
 * Return: length of string.
 */
size_t _strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		i++;
	}

	return (i);
}
