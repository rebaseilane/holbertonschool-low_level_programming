#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: The hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current, *tmp;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];

		while (current)
		{
			tmp = current->next;

			free(current->key);
			free(current->value);
			free(current);

			current = tmp;
		}
	}

	free(ht->array);
	free(ht);
}
