#include "header.h"

/**
 * delete_list - deletes a linked list.
 * @head: A linked list.
 *
 * Return: Void.
 */
void delete_list(dirlist *head)
{
	dirlist *node, *tmp_node;

	node = head;
	while (node)
	{
		tmp_node = node;
		node = node->next;
		free(tmp_node->name);
		free(tmp_node);
	}
}
