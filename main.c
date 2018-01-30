#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str;
	
	write(1, "\nfirst malloc\n", 15);
	str = malloc(sizeof(char) * 12);
//	printf("%x\n", str);
	write(1, "\nfirst free\n", 13);
	free(str);
	write(1, "\nsecond malloc\n", 16);
	str = malloc(sizeof(char) * 3);
//	printf("%x\n", str);
	write(1, "\nthird malloc\n", 15);
	str = malloc(sizeof(char) * 11);
	write(1, "\nprintf\n", 9);
	printf("%x\n", str);
	return 0;
}