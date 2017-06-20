#ifndef _LS_
#define _LS_

#include "hash_table.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

/* _strdup - duplicate a string. */
char *_strdup(char *str);

/* _strcmp - compares two strings. */
int _strcmp(const char *s1, const char *s2);

/* _strncmp - compares (n) amount of characters of two strings. */
int _strncmp(const char *s1, const char *s2, size_t n);

/* _strlen - gets the length of a string excluding the null byte. */
size_t _strlen(char *str);

/* process_command - process and store file info, directory lists and flags */
int process_command(hash_table_t *ht, char *cmd, int index);

/* format_output - change output based on flag, cmd or file info. */
void format_output(hash_table_t *ht);

#endif /* _LS _ */
