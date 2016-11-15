#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *funct_1(void *ptr);
void *funct_2(void *ptr);

int print_count = 0;
int run_now = 1;

int main(int argc, char *argv[])
{
	system("clear");
	pthread_t th1, th2;

	pthread_create(&th1, NULL, *funct_1, NULL);
	pthread_create(&th2, NULL, *funct_2, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	return 0;
}

void *funct_1(void *ptr)
{
	//int print_count = 0;
	while(print_count++ < 20)
		if (run_now == 1) {
			printf("1");
			run_now = 2;
		}
		else {
			sleep(1);
		}
}
void *funct_2(void *ptr)
{
	//int print_count = 0;
	while(print_count++ < 20)
		if (run_now == 2) {
			printf("2");
			run_now = 1;
		}
		else {
			sleep(1);
		}
}