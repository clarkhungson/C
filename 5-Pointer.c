// Talking about Pointer
#include <stdio.h>
int main(int argc, char *argv[])
{
	int a;
	int *p = &a;
	a = 10;
	printf("a = %d\n", a); 	
	printf("*p = %d\n", *p);
	printf("&a = %d\n", &a);
	printf("p = %d\n", p);

	return 0;
}