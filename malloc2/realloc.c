/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** malloc
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
	write(1, "realloc\n", 9);
	return (malloc(size));
}
