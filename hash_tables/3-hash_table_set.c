#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table
 * @key: The key (cannot be empty)
 * @value: The value
 *
 * Return: 1 if success, 0 if failure
 */
int hash_table_set(hash_table_t *ht, const char *key,
const char *value)
{
	hash_node_t *new_node, *current;
	unsigned long int index;
	char *dup_value;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	current = ht->array[index];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return (current->value ? 1 : 0);
		}
		current = current->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	dup_value = strdup(value);

	if (new_node->key == NULL || dup_value == NULL)
	{
		free(new_node->key);
		free(dup_value);
		free(new_node);
		return (0);
	}

	new_node->value = dup_value;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
