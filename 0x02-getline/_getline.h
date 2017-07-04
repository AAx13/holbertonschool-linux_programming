#ifndef _GETLINE_
#define _GETLINE_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* max size to be read from file descriptor. */
#define READ_SIZE 1
#define BUFFER 81

/* _getline - reads an entire line from a file descriptor. */
char *_getline(const int fd);

/* */
char *truncate_line(char *line_read);

/* */
size_t _strlen(char *str);

#endif /* _GETLINE_ */
