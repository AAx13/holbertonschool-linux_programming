#ifndef _GETLINE_
#define _GETLINE_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#define READ_SIZE 2

char *_getline(const int fd);
void *_realloc(void *ptr, size_t old, size_t new);
int check(char *line_read);
int putstr(char *str);
size_t _strlen(char *str);

#endif /* _GETLINE_ */
