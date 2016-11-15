// Bien dich trong Linux: 
// gcc -D_REENTRANT -o 19-thread 19-thread.c -lpthread
// Divide work to 2 thread, calculate time execution


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define N 1000000000


void *myfunc1(void *s1);
void *myfunc2(void *s2);

int i;
int S = 0;
int S1 = 0;
int S2 = 0;

int main(int argc, char *argv[])
{
	

	// Process with main thread and 1 thread
	pthread_t thread1, thread2;
	int ret1, ret2;
	char *s1 = "s1";
	char *s2 = "s2";


	ret1 = pthread_create(&thread1, NULL, myfunc1, (void *) s1);
	ret2 = pthread_create(&thread2, NULL, myfunc2, (void *) s2);

	
	// thread join: main thread wait until the longest thread finishes, 
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);


	int i;
	for (i = 0; i < 10; i++)
	{
		printf("Thread main    %d\n", i);
		sleep(1);
	}

	return 0;
}

void *myfunc1 (void *s1)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("Thread 1    %d\n", i);
		sleep(1);
	}
	return NULL;
}

void *myfunc2 (void *s2)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("Thread 2    %d\n", i);
		sleep(1);
	}
	return NULL;
}



