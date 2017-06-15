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

#endif /* _LS _ */
