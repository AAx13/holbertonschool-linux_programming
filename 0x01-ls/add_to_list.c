#include "header.h"

/**
 * add_to_list - adds file or directory to the list.
 * @head: A linked list.
 * @arg: An argument from stdin.
 *
 * Return: Void.
 */
void add_to_list(dirlist **head, char *arg)
{
	dirlist *new_node, *tmp_node;

	tmp_node = *head;
	new_node = malloc(sizeof(dirlist));
	if (!new_node)
	{
		perror("new_node");
		exit(EXIT_FAILURE);
	}

	if (tmp_node == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (tmp_node)
		{
			if (tmp_node->next == NULL)
			{
				tmp_node->next = new_node;
				break;
			}
			tmp_node = tmp_node->next;
		}
	}
	new_node->next = NULL;
	new_node->name = _strdup(file);
}
