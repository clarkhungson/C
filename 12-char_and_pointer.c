// Talking about Function
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str[24] = "First String";
	char *ptr = "Second String";

	printf("str = %s\n", str);
	printf("Size of str = %d\n", sizeof(str));

	printf("ptr = %s\n", ptr);
	printf("Size of ptr = %d\n", sizeof(ptr));

	return 0;
}