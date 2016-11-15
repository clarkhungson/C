#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p;
	p = malloc(sizeof(int));
	*p = 10;
	printf("%d\n", *p);
	printf("%p\n", p);
	return 0;
}
