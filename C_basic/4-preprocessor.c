#include <stdio.h>
#define N 100
#define Message \
	"Xin chao cac ban!"
#define Message_func(a, b) \
	printf(#a " va " #b " nghia la Forever Alone!\n");

// Include header
#include "4-myheader.h"

// Bo define PI trong file header, define lai
#undef PI
#define PI 3.1415

// Neu define PI roi, define tiep PI2, ham area_circle
#ifdef PI 
#define PI2 PI*2
float area_circle(float r)
{
	return r*r*PI;
}
#endif

// Neu chua define, thi define, neu define roi thi thoi
#ifndef PI
#define PI 3.14159
#else
#define PI_R 3.141591
#endif

int main(int argc, char *argv[])
{
	printf("%f\n", PI);
	printf("%f\n", PI2);
	printf("%s\n", Message);
	Message_func("F", "A");
	#if 1
	printf("A = 20, square = %f\n", square(20));
	#else
	printf("R = 2, area = %f\n", area_circle(2));
	#endif
	return 0;
}