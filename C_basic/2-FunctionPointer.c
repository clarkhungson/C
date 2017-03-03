#include <stdio.h>
#include <stdlib.h>

float inc(float a)
{
	return a + 1;
}

float dec(float b)
{
	return b - 1;
}

float (*func2)(float);

int main()
{
	float (*func)(float);
	func = &inc;
	func2 = dec;

	printf("%f\n", inc(10));
	printf("%f\n", (*func)(10));
	printf("%f\n", func2(10));
	return 0;
}