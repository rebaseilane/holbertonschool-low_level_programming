#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *name_copy;
	char *owner_copy;
	int i, len;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	/* copy name */
	if (name != NULL)
	{
		len = 0;
		while (name[len] != '\0')
			len++;
		name_copy = malloc(len + 1);
		if (name_copy == NULL)
		{
			free(d);
			return (NULL);
		}
		for (i = 0; i < len; i++)
			name_copy[i] = name[i];
		name_copy[len] = '\0';
		d->name = name_copy;
	}
	else
		d->name = NULL;

	d->age = age;

	/* copy owner */
	if (owner != NULL)
	{
		len = 0;
		while (owner[len] != '\0')
			len++;
		owner_copy = malloc(len + 1);
		if (owner_copy == NULL)
		{
			if (d->name != NULL)
				free(d->name);
			free(d);
			return (NULL);
		}
		for (i = 0; i < len; i++)
			owner_copy[i] = owner[i];
		owner_copy[len] = '\0';
		d->owner = owner_copy;
	}
	else
		d->owner = NULL;

	return (d);
}
