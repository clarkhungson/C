#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ret;
	printf("Calling execl...\n");
	ret = execl("/usr/bin/ls", "ls", "-l", NULL);
	printf("Dail execl... ret = %d\n", ret);
	return 0;
}