#include <stdio.h>
#include <stdlib.h>

union Data
{
	int i;
	float f;
	char str[20];
};

struct Data2
{
	int i;
	float f;
	char str[20];
};

int main()
{
	union Data data;
	struct Data2 data2;
	printf("Memory size occupied by data: %d\n", (int) sizeof(data));
	printf("Memory size occupied by data: %d\n", (int) sizeof(data2));
	return 0;
}