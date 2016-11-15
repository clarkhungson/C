// Send signal from termicl CTRL + C, send from cmd: kill -15 PID

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig) {
	printf("OUCH! - I got signal %d\n", sig);
	//signal(SIGINT, SIG_DFL);
}
// void handle_2(int sig)
// {
// 	printf("OUCH! - I got signal %d\n", sig);
// 	printf("Bye...\n");
// 	kill(getpid(), SIG_DFL);
// }

int main()
{
	int i = 0;
	signal(SIGINT, ouch);
	while(1) {
		printf("%d\n", i++);
		sleep(1);
	}
}