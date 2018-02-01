/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by rectoria
*/

#include "malloc.h"

static void resize_heap()
{
	metadata_t *temp = allocated;

	while (temp->next)
		temp = temp->next;
	if (temp + HEADER + temp->size + 1 != sbrk(0))
		return ;
	brk(temp);
}

static void merge()
{
	metadata_t *temp = allocated;

	while (temp) {
		if (temp->ptr + temp->size + 1 == temp->next) {
			temp->size += HEADER + temp->next->size;
			temp->next = temp->next->next;
			continue ;
		}
		temp = temp->next;
	}
	resize_heap();
}

void free(void *ptr)
{
	metadata_t *temp = allocated;

	write(2, "free\n", 5);
	while (ptr && temp && temp->ptr != ptr)
		temp = temp->next;
	if (!temp || !ptr)
		return ;
	temp->occupied = 0;
	merge();
	write(2, "endfree\n", 8);
}