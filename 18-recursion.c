#include <stdio.h>
int fibonaci(int n)
{
	if (n==1 || n==2) return 1;
	else
		return fibonaci(n-1) + fibonaci(n-2);
}
int main()
{
	for (int i = 1; i<10; i++)
		printf("%d\n", fibonaci(i));
}