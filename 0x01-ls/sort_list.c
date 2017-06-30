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
	dirlist *node, *next_node;

	node = head;
	while (node)
	{
		next_node = node->next;
		if (node->next
		    && _strcasecmp(node->name, next_node->name) > 0
		    && _strcmp(node->name, ".") != 0
		    && _strcmp(node->name, "..") != 0)
		{
			printf("HI sorting\n");
		}
		node = node->next;
	}

	file++;
	dir++;
}
