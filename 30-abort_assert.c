// abort(): 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	printf("Begin...\n");
	for (i = 0; i < 10; i++)
	{
		printf("i = %d\n", i);
		assert(i <= 5);
	}
	abort();
	printf("End...\n");
}