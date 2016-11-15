// 2 thread xen ke tang bien a len den 100

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* func_1(void *ptr);
void* func_2(void *ptr);
void* func_3(void *ptr);
int a = 0;
pthread_mutex_t lock;

int main(int argc, char *argv[])
{
	system("clear");
	pthread_t thd1, thd2;
	int t1, t2;
	char *mesg1 = "I'm Thread 1";
	char *mesg2 = "I'm Thread 2";

	t1 = pthread_create(&thd1, NULL, *func_1, (void *) mesg1);
	t2 = pthread_create(&thd2, NULL, *func_2, (void *) mesg2);

	pthread_join(thd1, NULL);
	pthread_join(thd2, NULL);


	return 0;
}

void * func_1(void *ptr)
{
	
	int i;
	for(i =0; a < 100; i++){
		
		if (a % 2 == 0)
		{
			pthread_mutex_lock(&lock);
			a = a + 1;
			printf("thead 1:  %d\t\n", a);
			pthread_mutex_unlock(&lock);
		}
		
		usleep(1);
	}
	
	
}

void * func_2(void *ptr)
{
	
	int i;
	for(i =0; a < 100; i++){
		
		if (a % 2 == 1)
		{
			pthread_mutex_lock(&lock);
			a = a + 1;
			printf("thread 2:  %d\t\n", a);
			pthread_mutex_unlock(&lock);
		}
		
		usleep(1);
	}
	
}
