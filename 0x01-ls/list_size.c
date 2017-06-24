#include "header.h"

/**
* list_size - get size of list.
* @head: Pointer to a linked list.
*
* Return: Size of the list.
*/
int list_size(dirlist *head)
{
	dirlist *node;
	int size;

	size = 0;
	node = head;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
