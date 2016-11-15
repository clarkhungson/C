// Talking about int type, char type, float type

#include <stdio.h>
int main(int argc, char *argv[])
{
	int k;
	int h;
	char ch;
	float f;
	double d;

	k = 24;
	printf("k = %d\n", k);
	printf("size of int: %d\n", sizeof(int));

	h = ++k *4;
	printf("zz = %d\n", h);

	ch = 66;
	printf("ch = %c\n", ch);
	printf("size of char: %d\n", sizeof(char));

	f = 2.2;
	printf("f = %f \n", f);
	printf("size of float: %d\n", sizeof(float));

	d = 123.4 * 7;
	printf("d = %f\n", d);
	printf("size of double: %d\n", sizeof(double));

	return 0;
}