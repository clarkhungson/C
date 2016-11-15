#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
 
static int exit_flag = 0;
 
static void hdl (int sig)
{
	exit_flag = 1;
}
 
int main (int argc, char *argv[])
{
	struct sigaction act;
 
	memset (&act, '\0', sizeof(act));
	act.sa_handler = &hdl;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	
	if (sigaction(SIGINT, &act, NULL) < 0) {
		perror ("sigaction");
		return 1;
	}
 
	while (!exit_flag)
		;
 
	return 0;
}