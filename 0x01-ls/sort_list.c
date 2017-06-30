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
	next_node = node->next;
	while (node && _strncmp(node->name, ".", 1) != 0)
	{
		if (node->next && _strcasecmp(node->name, next_node->name) < 0)
		{
			printf("Swappin %s and %s\n", node->name, next_node->name);
		}
		node = node->next;
	}
	file++;
	dir++;
}
