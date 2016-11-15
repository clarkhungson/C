// Bien dich trong Linux: 
// gcc -D_REENTRANT -o 19-thread 19-thread.c -lpthread
// Divide work to 2 thread, calculate time execution


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define N 1000000000


void *myfunc1(void *s1);
pthread_mutex_t lock;

int i;
int S = 0;
int S1 = 0;

int main(int argc, char *argv[])
{
	// Process with main thread
	clock_t begin = clock();
	for (i = 1; i < N; i++)
	{
		S = S + i;
	}
	clock_t end = clock();

	// Calculate time
	double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("Time process (main thread): %f\n", time_spent);





	// Process with main thread and 1 thread
	pthread_t thread1;
	int ret1;
	char *s1 = "s1";

	begin = clock();

	ret1 = pthread_create(&thread1, NULL, myfunc1, (void *) s1);

	// thread join to wait the longest thread
	pthread_join(thread1, NULL);


	S = S1;
	end = clock();

	// Calculate time
	time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("Time process (2 threads): %f\n", time_spent);

	return 0;
}

void *myfunc1 (void *s1)
{
	int i;
	for (i = 0; i < N/2; i++)
	{
		S1 = S1 + i;
	}
	return NULL;
}




