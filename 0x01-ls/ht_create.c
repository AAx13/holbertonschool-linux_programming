#include "hash_table.h"

/**
 * ht_create - Creates a hash table.
 * @size: Size of the array.
 *
 * Return: Pointer to new hash table.
 */
hash_table_t *ht_create(unsigned long int size)
{
	hash_table_t *new_ht;
	unsigned long int i;

	new_ht = malloc(sizeof(hash_table_t));
	if (!new_ht || size < 1)
	{
		return (NULL);
	}

	new_ht->array = malloc(sizeof(hash_node_t *) * size);
	if (!new_ht->array)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		new_ht->array[i] = NULL;
	}

	new_ht->size = size;

	return (new_ht);
}
