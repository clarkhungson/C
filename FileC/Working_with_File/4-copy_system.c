// copy a file with fgets(), fputc()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	//system("rm 2-file_out.jpg");
	unlink("rm 2-file_out.jpg");
	int c;
	FILE *in, *out;

	in = fopen("2-file_in.jpg", "r");
	out = fopen("2-file_out.jpg", "w");
	while((c = fgetc(in)) != EOF)
		fputc(c, out);

	// Giong pwd (sh)
	char st[100];
	printf("%s\n", getcwd(st, 100));
	
	exit(0);
}