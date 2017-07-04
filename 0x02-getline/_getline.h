#ifndef _GETLINE_
#define _GETLINE_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

/* max size to be read from file. */
#define READ_SIZE 1

#define BUFFER 64

/* _getline - reads an entire line from a file descriptor. */
char *_getline(const int fd);

/* _realloc - increase the size of the memory block pointed to by *ptr. */
void *_realloc(void *ptr, size_t old, size_t new);

/* putstr - writes a string to stdout. */
int putstr(char *str);

/* _strlen - returns length of a string excluding null byte. */
size_t _strlen(char *str);

#endif /* _GETLINE_ */
