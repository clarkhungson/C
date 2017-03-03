// Read and Write file "1-Demo.txt"

#include <stdio.h>
#include <stdlib.h>

int main() 
{

	FILE *f;
	char ch;
	int i = 0;
	char *st;
	system("clear");

	// Write to the file
	f = fopen("1-Demo.txt", "w");
	fprintf(f, "%s\n", "This is an example!");
	fputs("Write charaters from A to Z: ", f);
	for (i = 65; i <= 90; i++)
	{
		fputc(i, f);
	}
	fclose(f);

	// read from the file
	f = fopen("1-Demo.txt", "r");
	while(fscanf(f, "%c", &ch) != EOF)
	{
		printf("%c", ch);
	}
	printf("\n");
	fclose(f);

	return 0;
}
