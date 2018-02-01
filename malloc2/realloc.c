/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** malloc
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
	char *new = malloc(size);
	unsigned int i = 0;
	metadata_t *t = first;
	char *old;

	write(1, "realloc\n", 9);
	if (ptr == NULL || ptr > sbrk(0))
		return (NULL);
	while (t && t->data != ptr)
		t = t->next;
	if (t == NULL)
		return (NULL);
	if (t->size >= size)
		return (ptr);
	old = t->data;


	while (i < t->size) {
		new[i] = old[0];
		i++;
	}
	free(ptr);
	return (new);
}
