// See the id of process: ps aux|grep 29-Signal
// From terminal, we type the command: kill -15 id_process 

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void myhandle(int mysignal)
{
	printf("myhandle with signal %d\n", mysignal);
}

int main(int argc, char *argv[])
{
	int i = 0;
	signal(SIGTERM, myhandle);
	while(1)
	{
		printf("i = %d\n", i);
		i++;
		sleep(1);
	}
	return 0;
}