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
	dirlist *current, *next, *previous, *temp;
	int num_nodes, counter;

	temp = head;
	num_nodes = list_size(head);
	for (counter = 0; counter < num_nodes; counter++)
	{
		current = temp;
		next = current->next;
		previous = NULL;
		while (next != NULL)
		{
			if (_strcasecmp(current->name, next->name) > 0)
			{
				if (current == head)
				{
					temp = next;
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
}
