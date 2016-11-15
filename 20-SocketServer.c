// Bien dich trong Linux: 
// gcc -D_REENTRANT -o 19-thread 19-thread.c -lpthread


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


int main(int argc, char *argv[])
{
	/*Variable*/
	int sock;
	struct sockaddr_in server;
	int mysock;
	char buff[1024];
	int rval;


	/*Create socket*/
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock <0) {
		perror("Failed to create socket");
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);

	/*Call bind*/
	if(bind(sock, (struct sockaddr *)&server, sizeof(server))) 
	{
		perror("bind failed");
		exit(1);
	}

	/*Listen*/
	listen(sock, 5);

	/*Accept*/
	do {
		mysock = accept(sock, (struct sockaddr *) 0, 0);
		if (mysock == -1)
		{
			perror("accept failed");

		}
		else
		{
			memset(buff, 0, sizeof(buff));
			if ((rval = recv(mysock, buff, sizeof(buff), 0)) < 0)
				perror("reading stream message error");
			else if (rval == 0)
				printf("Ending connection\n");d
			else
				printf("MSG: %s\n", buff);
			
			printf("Got the message (rval = %d\n", rval);
			close(mysock);

		}

	} while (1);

	return 0;
}

