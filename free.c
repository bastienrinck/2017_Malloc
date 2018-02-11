/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by rectoria
*/

#include <signal.h>
#include "malloc.h"

static void resize_heap()
{
	metadata_t *temp = allocated->last;

	if (temp && !temp->occupied) {
		my_putstr("oe2\n");
		if (temp->prev_freed)
			temp->prev_freed->next_freed = NULL;
		else
			freed = NULL;
		if (temp->prev) {
			temp->prev->next = NULL;
			allocated->last = temp->prev;
		} else
			allocated = NULL;
		brk(temp);
	}
}

static void merge(metadata_t *p)
{
	metadata_t *del = p->next;

	if (!del || del->occupied)
		return ;
	if (del->prev_freed)
		del->prev_freed->next_freed = del->next_freed;
	else
		freed = del->next_freed;
	if (del->next_freed)
		del->next_freed->prev_freed = del->prev_freed;
	else
		allocated->last_freed = del->prev_freed;
	p->next = del->next;
	if (p->next) {
		p->next->prev = p;
		merge(p->next);
	}
}

void free(void *ptr)
{
	metadata_t *temp;

	my_putstr("free\n");
	if (!ptr)
		return;
	temp = ptr - HEADER;
	if (temp->ptr != ptr || !temp->occupied)
		return;
	lock_thread(0);
	temp->next_freed = NULL;
	temp->prev_freed = NULL;
	if (!freed)
		freed = temp;
	else {
		allocated->last_freed->next_freed = temp;
		temp->prev_freed = allocated->last_freed;
	}
	allocated->last_freed = temp;
	temp->occupied = 0;
	for (; temp->prev && !temp->prev->occupied; temp = temp->prev)
		my_putstr("ah\n");
	
	my_putstr("oe\n");
	merge(temp);
	resize_heap();
	unlock_thread(0);
	my_putstr("endfree\n");
}
