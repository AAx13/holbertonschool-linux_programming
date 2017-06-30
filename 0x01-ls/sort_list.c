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
	dirlist *node, *next_node, *prev_node;

	node = head;
	prev_node = NULL;
	while (node && _strncmp(node->name, ".", 1) != 0)
	{
		next_node = node->next;
		if (node->next && _strcasecmp(node->name, next_node->name) > 0)
		{
			if (prev_node)
			{
				prev_node->next = next_node;
			}
			node->next = next_node->next;
			next_node->next = node;
		}
		prev_node = node;
		node = node->next;
	}
	file++;
	dir++;
}
