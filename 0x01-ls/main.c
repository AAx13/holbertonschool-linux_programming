#include "header.h"

/**
 * main - mainfile.
 * @ac: Amount of args.
 * @av: Array of strings containing args.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int ac, char **av)
{
	hash_table_t *ht;
	int i, x;

	av++;
	i = 1;
	x = 0;
	if (!*av)
	{
		ht = ht_create(ac + 1);
		process_command(ht, ".", i);
	}
	else
	{
		ht = ht_create(ac);
		while (*av)
		{
			process_command(ht, *av, i);
			if (strncmp(*av, "-", 1) != 0)
			{
				x++;
				i++;
			}
			av++;
		}
		if (x == 0)
		{
			process_command(ht, ".", i);
		}
	}
	format_output(ht);

	ht_delete(ht);

	return (EXIT_SUCCESS);
}
