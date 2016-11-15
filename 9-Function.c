// Talking about Function
#include <stdio.h>
int add(int a, int b) {
	int sum;
	sum = a + b;
	return sum;
}
int giaithua(int n)
{
	if (n==0) return 1;
	else
		return giaithua(n-1)*n;
}
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(int argc, char *argv[])
{
	int a = 10;
	int b = 20;

	printf("3+12 = %d\n", add(3,12));
	printf("6! = %d\n", giaithua(6));

	swap(&a,&b);
	printf("a = %d\nb = %d\n", a,b);

	return 0;
}