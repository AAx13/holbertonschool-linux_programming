#include "header.h"

void option_1(hash_table_t *ht)
{
	hash_node_t *node;
	unsigned int i;

	for (i = 1; ht->array[i]; i++)
	{
		node = ht->array[i];
		if (ht->size > 3 && strcmp(node->key, "file") != 0)
		{
			printf("%s:\n", node->key);
		}
		while (node)
		{
			if (strncmp(node->value, ".", 1) != 0)
			{
				printf("%s", node->value);
				if (node->next)
				{
					printf("\n");
				}
			}
			node = node->next;
		}
		if (ht->size > 3 && i != ht->size - 2)
		{
			printf("\n\n");
		}
	}
}
