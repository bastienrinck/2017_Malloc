#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *b = sbrk(0);
	if (!brk(b + 10000000))
		write(2, "should work\n", 13);
	sleep(15);
}
