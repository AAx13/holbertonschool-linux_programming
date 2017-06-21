#ifndef _LS_
#define _LS_

#include "list.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>



/* _strdup - duplicate a string. */
char *_strdup(char *str);

/* _strcmp - compares two strings. */
int _strcmp(const char *s1, const char *s2);

/* _strncmp - compares (n) amount of characters of two strings. */
int _strncmp(const char *s1, const char *s2, size_t n);

/* _strlen - gets the length of a string excluding the null byte. */
size_t _strlen(char *str);



/* print_error - prints error based on errno. */
int print_error(char *arg);

/* print_cwd - print contents of current working directory. */
int print_cwd(void);

/* process_arg - send arg info to their respective structs. */
int process_arg(dirlist **head, char *arg);

/* build_list - builds list containing information on a file or directory. */
void build_list(dirlist **head, char *arg, int i);

#endif /* _LS _ */
