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

/**
 *
int main(void)
{
	dirlist *head;

	head = NULL;
	add_to_list(&head, "second node", "abc", 0, 1);
	add_to_list(&head, "fourth node", "ABC", 0, 1);
	add_to_list(&head, "fifth node", "folder1", 0, 1);
	add_to_list(&head, "first node", "file3", 0, 1);
	add_to_list(&head, "third node", "File2", 0, 1);
	print_list(head, 0, 0);
	printf("<-------->\n");
	head = sort_list(head, 0, 0);
	printf("<-------->\n");
	print_list(head, 0, 0);
	delete_list(head);

	return (0);
}
*/
