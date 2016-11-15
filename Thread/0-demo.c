#include <stdio.h>
#include <stdlib.h>
int main() {
	void *st = "Hello world";
	printf("%s\n", (char *) st);
	return 0;
}