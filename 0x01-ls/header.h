#ifndef _LS_
#define _LS_

#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>

/**
 * struct dirlist_s - contains list of all items in a directory.
 * @arg: Original arg this node came from.
 * @name: Name of file or directory.
 * @type: File or directory.
 * @id: Used to identify each group of lists within the list.
 * @next: Next file or directory.
 *
 * Description: This struct contains the files or directories from a
 * directory as well as information on them.
 */
typedef struct dirlist_s
{
	char *arg;
	char *name;
	int type;
	int id;
	struct dirlist_s *next;
} dirlist;



/* add_to_list - adds file or directory to the list. */
void add_to_list(dirlist **head, char *arg, char *name, int type, int id);

/* print_list - prints a linked list. */
void print_list(dirlist *head, int dir, int file);

/* sort_list - sorts list based on type and options */
dirlist *sort_list(dirlist *head, int dir, int file);

/* list_size - get size of list. */
int list_size(dirlist *head);

/* delete_list - deletes a linked list. */
dirlist *delete_list(dirlist *head);



/* _tolower - convert letter to lower case. */
int _tolower(int c);

/* _strdup - duplicate a string. */
char *_strdup(char *str);

/* _strcmp - compares two strings. */
int _strcmp(const char *s1, const char *s2);

/* _strncmp - compares (n) amount of characters of two strings. */
int _strncmp(const char *s1, const char *s2, size_t n);

/* _strcasecmp - compare two strings ignoring case. */
int _strcasecmp(const char *s1, const char *s2);

/* _strlen - gets the length of a string excluding the null byte. */
size_t _strlen(char *str);



/* print_error - prints error based on errno. */
int print_error(char *arg);

/* print_dirs - prints contents of 2 or more directories. */
void print_dirs(dirlist *head, int dirs);

/* process_arg - send arg info to their respective structs. */
int process_arg(dirlist **head, char *arg, int id);

/* build_list - builds list containing information on a file or directory. */
void build_list(dirlist **head, char *arg, int i, int id);

#endif /* _LS _ */
