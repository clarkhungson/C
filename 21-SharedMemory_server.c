#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main(int argc, char *argv[])
{
	int shmid;
	key_t key;
	char *shm;
	char *s;

	key = 9876;

	// Create Shared Memory ID
	shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);
	if(shmid < 0)
	{
		perror("shmget");
		exit(1);
	}

	// Create Shared Memory
	shm = shmat(shmid, NULL, 0);

	if(shm == (char *) -1)
	{
		perror("shmat");
		exit(1);
	}

	// Write st to Shared Memory
	memcpy(shm, "Hello World", 11);

	s = shm;
	s += 11;

	*s = 0;

	while(*shm != '*')
		sleep(1);
	
	return 0;
}
