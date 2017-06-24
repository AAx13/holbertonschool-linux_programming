#include "header.h"

/**
 * sort_list - sorts list based on type and options.
 * @head: A linked list.
 * @dir: Amount of directory args.
 * @file: Amount of file args.
 *
 * Return: Void.
 */
void sort_list(dirlist *head, int dir, int file)
{
	dirlist *node;

	node = head;
	while (node)
	{
		node = node->next;
	}
	file++;
	dir++;
}
