/*
** EPITECH PROJECT, 2017
** malloc
** File description:
** malloc
*/

#pragma once

#include <unistd.h>

typedef struct metadata_s metadata_t;

struct metadata_s {
	size_t size;
	void *self;
	void *data;
	metadata_t *next;
	int free;
};

void *malloc(size_t);
void free(void *);
void *realloc(void *, size_t);

#define HEADER (sizeof(metadata_t))
#define align(x) (((((x)-1)>>2)<<2)+4)

extern metadata_t *first;
