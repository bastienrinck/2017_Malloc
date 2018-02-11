#include <stdio.h>
#include <stdlib.h>

#define TOTAL_ALLOCS 20000
#define ALLOC_SIZE 1024*1024

int main() {
	void *a = malloc(10);
	void *b = malloc(10);
	void *c = malloc(10);
	void *d = malloc(10);
	void *e = malloc(10);
	void *f = malloc(10);
	free(a);
	free(d);
	free(b);
	free(c);


  return 0;
}
