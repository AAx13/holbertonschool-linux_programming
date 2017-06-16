#include "header.h"

void format_options(hash_table_t *ht)
{
	hash_node_t *flag_node;

	flag_node = ht->array[0];
	while (flag_node)
	{
		while (*flag_node->value)
		{
			switch (*flag_node->value)
			{
				case '1':
					option_1(ht);
					break;

				case 'a':
					printf("The -a flag is here\n");
					break;
			}
			flag_node->value++;
		}
		flag_node = flag_node->next;
	}
}
