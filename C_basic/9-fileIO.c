#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char ch;
	char buf[100];

	fp = fopen("9-fileIO.text", "w+");
	fprintf(fp, "Hello World!\n");
	fputc(65, fp);
	fputs("\nHave a nice day..", fp);
	fclose(fp);

	fp = fopen("9-fileIO.text", "r+");
	ch = fgetc(fp);
	printf("%c\n", ch);
	fgets(buf, 100, fp);
	printf("%s\n", buf);
	fgets(buf, 100, fp);
	printf("%s\n", buf);
	fgets(buf, 100, fp);
	printf("%s\n", buf);
	fgets(buf, 100, fp);
	printf("%s\n", buf);
	fclose(fp);
	return 0;
}