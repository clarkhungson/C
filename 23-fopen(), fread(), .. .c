#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fs;
	char buf[10];
	size_t sz;

	fs = fopen("mytext.txt", "r");
	if (fs == NULL)
	{
		perror("fopen");
		exit(1);
	}

	while(!feof(fs))
	{
		sz = fread((void *) buf, 10, 1, fs);
		//buf[9] = '\0';
		printf("%s", buf);
	}

	printf("\n");
	fclose(fs);
	return 0;
}