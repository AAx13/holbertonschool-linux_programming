#include "header.h"

/**
 * format_output - change output based on flag, cmd or file info.
 * @ht: A hash table.
 *
 * Return: Void.
 */
void format_output(hash_table_t *ht)
{
	hash_node_t *node;
	unsigned int i;

	if (!ht || !ht->array)
	{
		return;
	}

	if (ht->array[0])
	{
		printf("These are options");
	}
	else if (ht->size == 1)
	{
		for (node = ht->array[1]; node; node = node->next)
		{
			if (strncmp(node->value, ".", 1) != 0)
			{
				printf("%s  ", node->value);
			}
		}
	}
	else
	{
		for (i = 1; i < ht->size; i++)
		{
			node = ht->array[i];
			if (ht->size > 2 && strcmp(node->key, "file") != 0)
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
			if (ht->size > 2 && i != ht->size - 1)
			{
				printf("\n\n");
			}
		}
	}
	printf("\n");
}
