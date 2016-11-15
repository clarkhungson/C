#include <stdio.h>

enum Days {mon = 2, tue, wed, thu, fri, sat};

int main()
{
	enum Days day;
	day = mon;
	printf("Current day: %d\n", day);
	printf("Friday: %d\n", fri);
	return 0;
}