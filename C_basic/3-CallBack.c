#include <stdio.h>
#include <stdlib.h>

int inc(int a){
	return a + 1;
}

int dec(int a) {
	return a - 1;
}

int process(int a, int (*func)(int))
{
	return func(a*10);
}

int main()
{
	int (*ptr_func)(int) = &inc;

	printf("%d\n", process(10, dec));
	return 0;
}