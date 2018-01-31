/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** malloc
*/

#include "malloc.h"

metadata_t *first = NULL;

void *init_heap(size_t size)
{
	first = sbrk(0);
	if (brk(first + HEADER + size) == -1)
		return (NULL);
	first->size = size;
	first->self = first;
	first->data = first + HEADER;
	first->next = NULL;
	first->free = 0;
	return (first + HEADER);
}

void *reserve_next(size_t size)
{
	metadata_t *t = first;
	metadata_t *current = sbrk(0);

	while (t->next)
		t = t->next;
	if (brk(current + HEADER + size) == -1)
		return (NULL);
	current->size = size;
	current->self = current;
	current->data = current + HEADER;
	current->next = NULL;
	current->free = 0;
	t->next = current;
	// write(2, "allocated\n", 11);
	return (current + HEADER);
}

void *check_free(size_t size)
{
	metadata_t *t = first;

	while (t) {
		if (t->free && t->size >= size)
			return (t);
		t = t->next;
	}
	// write(2, "nothing\n", 9);
	return (NULL);
}

void *reserve_free(size_t size)
{
	metadata_t *reclaimed = check_free(size);

	// write(2, "malloc claimed\n", 16);
	reclaimed->free = 0;
	return (reclaimed + HEADER);
}

void *malloc(size_t size)
{
	size = align(size);
	write(2, "malloc\n", 8);
	if (first == NULL)
		return (init_heap(size));
	if (check_free(size))
		return (reserve_free(size));
	return (reserve_next(size));
}
