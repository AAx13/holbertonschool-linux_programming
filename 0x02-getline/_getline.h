#ifndef _GETLINE_
#define _GETLINE_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* max size to be read from file descriptor. */
#define READ_SIZE 1
#define BUFFER 1024

/* _getline - reads an entire line from a file descriptor. */
char *_getline(const int fd);

size_t _strlen(char *str);

#endif /* _GETLINE_ */
