#include <stdio.h>


int main(int argc, char *argv[])
{
	printf("File:%s\n", __FILE__);
	printf("Date:%s\n", __DATE__);
	printf("Time:%s\n", __TIME__);
	printf("Line:%d\n", __LINE__);
	printf("Ansi:%d\n", __STDC__);
	//printf("Function:%d\n", __FUNC__);
	return 0;
}