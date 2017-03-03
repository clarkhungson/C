#include <stdio.h>
#include <string.h>

char *int2str(int);
char str[10];

int main()
{
	char s[10] = "Hello";
	char s2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
	char *s3 = (char *) malloc(10*sizeof(char));

	printf("%s\n", s2);
	printf("%d\n", (int)strlen(s2));
	strcpy(s3, s);
	printf("%s\n", s3);

	printf("%s\n", int2str(2134));
	return 0;
}

char *int2str(int n)
{
	int i = 0;
	while (n > 0)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	return str;
}