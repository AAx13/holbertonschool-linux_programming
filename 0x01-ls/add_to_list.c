#include "header.h"

/**
 * add_to_list - adds file or directory to the list.
 * @head: A linked list.
 * @arg: Original arg from stdin.
 * @name: Name of the file or directory.
 * @type: 0 if dir 1 if file.
 * @id: Used to identify each arg group.
 *
 * Return: Void.
 */
void add_to_list(dirlist **head, char *arg, char *name, int type, int id)
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
	new_node->arg = _strdup(arg);
	new_node->name = _strdup(name);
	new_node->type = type;
	new_node->id = id;
}
