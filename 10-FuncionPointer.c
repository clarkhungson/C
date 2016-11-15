// Talking about Function
#include <stdio.h>
int add(int a, int b) {
	int sum;
	sum = a + b;
	return sum;
}

int main(int argc, char *argv[])
{
	int (*myfunct_ptr)(int, int);
	myfunct_ptr = &add;

	printf("3+12 = %d\n", add(3,12));
	printf("3+12 = %d\n", myfunct_ptr(3,12));

	return 0;
}