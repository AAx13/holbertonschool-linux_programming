#include "header.h"

/**
 * print_list - prints a linked list.
 * @head: A linked list.
 * @dir: Amount of directory args.
 * @file: Amount of file args.
 *
 * Return: Void.
 */
void print_list(dirlist *head, int dir, int file)
{
	dirlist *node;

	node = head;
	if (dir < 2 && file < 2)
	{
		while (node)
		{
			if (_strncmp(node->name, ".", 1) != 0)
			{
				printf("%s  ", node->name);
			}
			node = node->next;
		}
		printf("\n");
	}
	else if (dir > 1)
	{
		print_dirs(head, dir);
	}
}
