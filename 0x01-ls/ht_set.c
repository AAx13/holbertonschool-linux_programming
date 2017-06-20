#include "header.h"

/**
 * ht_set - Adds an element to the hash table.
 * @ht: A hash table.
 * @key: Key used to index where the new element is stored.
 * @value: Values to store in the new element node.
 * @index: Index of the array..
 *
 * Return: 0 if succeeded, 1 otherwise.
 */
int ht_set(hash_table_t *ht, char *key, char *value, int index)
{
	hash_node_t *new_node, *head;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node || !key || !ht)
	{
		return (1);
	}

	head = ht->array[index];
	if (!ht->array[index])
	{
		ht->array[index] = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		while (head)
		{
			if (head->next == NULL)
			{
				head->next = new_node;
				new_node = head->next;
				new_node->prev = head;
				new_node->next = NULL;
			}
			head = head->next;
		}
	}
	new_node->key = _strdup(key);
	new_node->value = _strdup(value);

	return (0);
}
