#ifndef _LS_
#define _LS_

#include "hash_table.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

/* process_command - process and store file info, directory lists and flags */
int process_command(hash_table_t *ht, char *cmd, int index);

/* format_output - change output based on flag, cmd or file info. */
void format_output(hash_table_t *ht);

/* format_options - format output with options flags */
void format_options(hash_table_t *ht);

/* option_1 - print with -1 option */
void option_1(hash_table_t *ht);

/* option_a - print with -a option */
void option_a(hash_table_t *ht);

#endif /* _LS _ */
