#ifndef _LIST_
#define _LIST_

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
void sort_list(dirlist *head, int dir, int file);

/* list_size - get size of list. */
int list_size(dirlist *head);

/* delete_list - deletes a linked list. */
dirlist *delete_list(dirlist *head);

#endif /* _LIST_ */
