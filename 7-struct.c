// Talking about Pointer
#include <stdio.h>

int main(int argc, char *argv[])
{
	struct 
	{
		int a;
		float b;
		int c;
	} myst;

	myst.a = 4;
	myst.b = 3.2;
	myst.c = 2;

	printf("a = %d, b = %f, c = %d\n", myst.a, myst.b, myst.c);
	return 0;
}