#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	void *str;

	str = malloc(10);
	printf("MALLOC: %p\n", str);
	free(str);
	str = malloc(9);
	printf("MALLOC2: %p\n", str);
	free(str);
	str = malloc(10);
	printf("MALLOC3: %p\n", str);
	return (0);
}