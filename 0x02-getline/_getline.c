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
	size_t count, line_size, buffer;
	char line_read[READ_SIZE];
	char *line_out;

	count = 0;
	line_size = 0;
	buffer = READ_SIZE;
	line_out = malloc(sizeof(char) * buffer);
	if (fd == -1 || !line_out)
	{
		return (NULL);
	}

	memset(line_out, 0, 2);
	do {
		count = read(fd, line_read, READ_SIZE);
		if (count == 0 && line_size == 0)
		{
			free(line_out);
			return (NULL);
		}
		else
		{
			line_read[count] = '\0';
			line_size += count;
		}

		while (line_size >= buffer)
		{
			buffer += line_size;
			line_out = _realloc(line_out, line_size, buffer);
		}
		strcat(line_out, line_read);


	} while (count);

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
