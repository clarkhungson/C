#include <stdio.h>
#include <stdlib.h>
#define VAL 4095

// int func(int * arr) {
// 	int m = 0;
// 	int n = 4095;
// 	int p;
// 	if (arr[m] == VAL){
// 		p = m;
// 		return p;
// 	}
// 	if (arr[n] == VAL){
// 		p = n;
// 		return p;
// 	}
// 	printf("something!\n");
// 	while (m < n){
// 		p = (m + n) / 2;
// 		if (arr[p] < VAL){
// 			m = p;
// 		}
// 		else{
// 			n = p;
// 		}
// 		printf("m = %d, n = %d\n", m, n);
// 	}
// 	printf("m = %d, n = %d\n", m, n);
// 	return p;
// }

// int func(int * arr) {
// 	int m = 0;
// 	int n = 4095;
// 	int p = 0;

// 	// if (arr[m] == VAL){
// 	// 	p = m;
// 	// }
// 	// if (arr[n] == VAL){
// 	// 	p = n;
// 	// }
// 	while (m + 1 < n){
// 		p = (m + n) / 2;
// 		if (arr[p] < VAL){
// 			m = p;
// 		}
// 		else{
// 			n = p;
// 		}
// 		printf("m = %d, n = %d\n", m, n);
// 	}
// 	return p;
// }

int m = 0;
int n = 4095;
int p = 0;

int func(int * arr, int m, int n) {
	if (m + 1 == n) return m;
	p = (m + n) / 2;
	
	if (arr[p] == VAL) return p;
	else if (arr[p] < VAL){
		return func(arr, p, n);
	}
	else{
		return func(arr, m, p);
	}
}

int main()
{
	int arr[4096];
	int i = 0;
	int result = 0;
	for (i = 0; i < 4096; i++) {
		arr[i] = i;
	}
	result = func(arr, m, n);
	printf("Id of %d: %d\n", VAL, result);
	return 0;
}
