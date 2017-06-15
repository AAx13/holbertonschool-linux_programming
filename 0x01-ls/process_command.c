#include "header.h"

/**
 * process_command - process and store file info, directory lists and flags.
 * @ht: A hash table.
 * @cmd: A command.
 * @index: Index to store into hash table.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int process_command(hash_table_t *ht, char *cmd, int index)
{
	struct dirent *read;
	DIR *dirp;

	if ((dirp = opendir(cmd)) == NULL)
	{
		perror(cmd);
		exit(EXIT_FAILURE);
	}

	if ((read = readdir(dirp)) == NULL)
	{
		perror("readdir");
		exit(EXIT_FAILURE);
	}

	while (read)
	{
		ht_set(ht, cmd, read->d_name, index);
		read = readdir(dirp);
	}

	return (EXIT_SUCCESS);
}
