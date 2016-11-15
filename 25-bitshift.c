#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* bin2str(int a)
{
	char *s;
	s = (char *) malloc(8 * sizeof(char));
	strcpy(s, "00000000");
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		if(a % 2 == 0) s[7-i] = '0';
			else s[7-i] = '1';
		a = a / 2;
		if (a == 0) break;
	}
	return s;
}

int main(int argc, char *argv[])
{
	
	char bits = 153;
	int shift = 1;
	system("clear");
	
	printf("Original     : %s\n", bin2str(bits));
	printf("Shift left %d : %s\n", shift, bin2str(bits << shift));
	printf("Shift right %d: %s\n", shift, bin2str(bits >> shift));

	return 0;
}