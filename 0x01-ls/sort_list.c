#include "header.h"

/**
 * sort_list - sorts list based on type and options.
 * @head: A linked list.
 * @dir: Amount of directory args.
 * @file: Amount of file args.
 *
 * Return: Void.
 */
dirlist *sort_list(dirlist *head, int dir, int file)
{
	dirlist *current, *next, *previous;
	int num_nodes, counter, compare;

	compare = 0;
	num_nodes = list_size(head);
	for (counter = 0; counter < num_nodes; counter++)
	{
		current = head;
		next = current->next;
		previous = NULL;
		while (next != NULL)
		{
			compare = _strcasecmp(current->name, next->name);
			if (compare > 0)
			{
				if (current == head)
				{
					head = next;
				}
				else
				{
					previous->next = next;
				}
				current->next = next->next;
				next->next = current;
				previous = next;
				next = current->next;
			}
			else
			{
				previous = current;
				current = current->next;
				next = current->next;
			}
		}
	}
	dir++;
	file++;
	return (head);
}
