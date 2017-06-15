#include "hash_table.h"

/**
 * ht_print - Prints a hash table.
 * @ht: A hash table.
 *
 * Return: Void.
 */
void ht_print(const hash_table_t *ht)
{
	unsigned int i;
	hash_node_t *node;

	if (!ht || !ht->array)
	{
		return;
	}

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		if (ht->size > 1)
		{
			printf("%s:\n", node->key);
		}
		while (node)
		{
			if (strncmp(node->value, ".", 1) != 0)
			{
				printf("%s  ", node->value);
			}
			node = node->next;

		}
		printf("\n");
	}
}
