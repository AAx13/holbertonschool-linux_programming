#include "header.h"

/**
 * print_dirs - prints conents of 2 or more directories.
 * @head: Pointer to head of linked list.
 * @dirs: Amount of directory args.
 *
 * Return: Void.
 */
void print_dirs(dirlist *head, int dirs)
{
	dirlist *node, *next_node;

	node = head;
	next_node = NULL;
OUT:
	if (dirs)
	{
		next_node = node->next;
		printf("%s:\n", node->arg);
		while (node)
		{
			if (_strncmp(node->name, ".", 1) != 0)
			{
				if (node->id == next_node->id)
				{
					printf("%s  ", node->name);
				}
				else
				{
					if (dirs != 0)
					{
						printf("\n\n");
					}
					goto OUT;
				}
			}
			node = node->next;
		}
		dirs--;
	}
	printf("\n");
}
