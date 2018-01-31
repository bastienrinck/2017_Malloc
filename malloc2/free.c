/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** malloc
*/

#include <stdio.h>
#include "malloc.h"

void free(void *ptr)
{
	metadata_t *t = first;

	write(2, "free\n", 5);
	if (ptr == NULL || ptr > sbrk(0))
		return ;
	while (t && t->data != ptr)
		t = t->next;
	if (t == NULL)
		return ;
	t->free = 1;
}
