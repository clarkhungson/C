#include <stdio.h>
#include <stdlib.h>

void do_file(char *path, char *str)
{
	FILE *fp;
	fp = fopen(path, "r+");
	int c;
	int i = 0;
	while((c = getc(fp)) != EOF)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\n';
}

int main()
{
	char s[1200];
	do_file("main.html", s);
	printf("%s", s);
	return 0;
}