#ifndef _LS_
#define _LS_

#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>

typedef struct dir_s
{
  char *file;
  struct dir_t *next;
  struct dir_t *prev;
} dir_list;

/* definition of directory list */
extern dir_list *list;

#endif /* _LS _ */
