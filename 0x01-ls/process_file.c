#include "header.h"

/**
 * process_file - process and store file info.
 * @ht: A hash table.
 * @cmd: A command.
 * @index: Index to store into hash table.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int process_file(hash_table_t *ht, char *file, int index)
{
	/* just store filename for now */
	ht_set(ht, "file", file, index);

	return (EXIT_SUCCESS);
}
