#ifndef _HASH_
#define _HASH_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
 typedef struct hash_node_s
 {
	 char *key;
	 char *value;
	 struct hash_node_s *next;
	 struct hash_node_s *prev;
 } hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
 typedef struct hash_table_s
 {
	 unsigned long int size;
	 hash_node_t **array;
 } hash_table_t;

/* ht_create - Creates a hash table. */
hash_table_t *ht_create(unsigned long int size);

/* ht_set - Adds an element to the hash table. */
int ht_set(hash_table_t *ht, const char *key, const char *value, int index);

/* ht_print - Prints a hash table. */
void ht_print(const hash_table_t *ht);

#endif /* _HASH_ */
