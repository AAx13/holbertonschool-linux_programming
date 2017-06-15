#include "header.h"

int main(int ac, char **av)
{
	hash_table_t *ht;
	int i;

	av++;
	i = 0;
	if (!*av)
	{
		ht = ht_create(ac);
		process_command(ht, ".", i);
	}
	else
	{
		ht = ht_create(ac - 1);
		while (*av && i < ac)
		{
			process_command(ht, *av, i);
			i++;
			av++;
		}
	}
	ht_print(ht);
	return (EXIT_SUCCESS);
}
