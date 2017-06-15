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

	i = 0;
	if (!ht->array[0])
	{
		i = 1;
	}
	while (ht->array[i])
	{
		node = ht->array[i];
		printf("%s:\n", node->key);
		while (node)
		{
			printf("%s  ", node->value);
			node = node->next;
		}
		printf("\n");
		i++;
	}
}
