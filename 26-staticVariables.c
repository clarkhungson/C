#include <stdio.h>

int myfunc()
{
	static int i = 0;
	i += 2;
	printf("i = %d\n", i);
	i += 2;
	printf("i = %d\n", i);
	printf("\n");
	return 0;
}
int main(int argc, char *argv[]) 
{
	myfunc();
	myfunc();
	return 0;
}