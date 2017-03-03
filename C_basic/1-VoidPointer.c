#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	void * ptr;
	int a = 10;
	ptr = &a;
	printf("%d\n", *(int *)ptr);
	
	return 0;
}