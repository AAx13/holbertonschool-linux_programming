#ifndef _GETLINE_
#define _GETLINE_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#define READ_SIZE 17

char *_getline(const int fd);
char *truncate_line(char *line_out);
char *split_line(char *line_read, char *line_out);
void *_realloc(void *ptr, size_t old, size_t new);
int putstr(char *str);
size_t _strlen(char *str);

#endif /* _GETLINE_ */
