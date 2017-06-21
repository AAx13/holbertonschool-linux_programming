#ifndef _LIST_
#define _LIST_


/**
 * struct list_s - contains list of all items in a directory.
 * @name: Name of file or directory.
 * @next: Next file or directory.
 *
 * Description: This struct contains the files or directories from a
 * directory as well as information on them.
 */
typedef struct dirlist_s
{
	char *name;
	struct dirlist_s *next;
} dirlist;



/* add_to_list - adds file or directory to the list. */
void add_to_list(dirlist **head, char *arg);

/* print_list - prints a linked list. */
void print_list(dirlist *head);

/* delete_list - deletes a linked list. */
void delete_list(dirlist *head);



#endif /* _LIST_ */
