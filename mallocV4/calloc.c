/*
** EPITECH PROJECT, 2021
** PSU_2017_malloc
** File description:
** Created by rectoria
*/

#include "malloc.h"

void my_memset(void *ptr, const char c, size_t size)
{
	char *cptr = ptr;
	for (int i = 0; i < size; i++)
		cptr[i] = c;
}

void *calloc(size_t nmeb, size_t size)
{
	void *temp = NULL;

	write(1, "Calloc\n", 7);
	if (nmeb && size)
		temp = malloc(nmeb * size);
	my_memset(temp, 0, nmeb * size);
	return (temp);
}