#include "header.h"

/**
 * print_list - prints a linked list.
 * @head: A linked list.
 *
 * Return: Void.
 */
void print_list(dirlist *head)
{
	dirlist *node;

	node = head;
	while (node)
	{
		printf("%s  ", node->name);
		node = node->next;
	}
	printf("\n");
}
