// Recursion: Tim UCLN cua a va b

#include <stdio.h>
#include <stdlib.h>

int UCLN(int m, int n)
{
	if (m*n == 0) return (m + n);
		else
			if (m > n) return UCLN(n, m - n);
				else return UCLN(m, n - m);
}

int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("UCLN cua %d va %d la: %d\n", a, b, UCLN(a, b));
	return 0;
}