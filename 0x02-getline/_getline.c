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
	size_t count, buffer;
	char *line_read;
	unsigned int i;
	char c;

	buffer = 64;
	i = 0, c = 0;
	line_read = malloc(sizeof(char) * buffer);
	if (!line_read || fd == -1)
	{
		free(line_read);
		return (NULL);
	}

	count = read(fd, &c, READ_SIZE);
	while (count || i > 0)
	{
		if (errno && i > 0)
		{
			free(line_read);
			return (NULL);
		}

		if (c == '\n' || count == 0)
		{
			line_read[i] = '\0';
			return (line_read);
		}

		if (i == buffer)
		{
			line_read = _realloc(line_read, i, i + buffer);
		}

		line_read[i++] = c;
		count = read(fd, &c, READ_SIZE);
	}
	free(line_read);
	return (NULL);
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
		return (malloc(new));
	}
	else if (new <= old)
	{
		return (ptr);
	}
	else
	{
		new_ptr = malloc(new);
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
 * _strlen - gets the length of a string excluding the null byte.
 * @str: A string.
 *
 * Return: Length of a string.
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
