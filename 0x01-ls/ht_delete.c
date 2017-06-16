#include "hash_table.h"

/**
 * ht_delete - Deletes a hash table.
 * @ht: A hash table.
 *
 * Return: Void.
 */
void ht_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *tmp_node;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			tmp_node = node;
			node = node->next;
			free(tmp_node->key);
			free(tmp_node->value);
			free(tmp_node);
		}
	}
	free(ht->array);
	free(ht);
}
