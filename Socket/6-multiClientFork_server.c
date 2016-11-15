// Xu ly nhieu client di den, su dung fork()


#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int id = 0;
int main(int argc, char *argv[])
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	char st[5];

	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = 1996;
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	// Create a connection queue and wait for clients
	listen(server_sockfd, 5);
	signal(SIGCHLD, SIG_IGN);
	while(1) {
		printf("server waiting\n");

		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd,
			(struct sockaddr *)&client_address, &client_len);
		if(fork() == 0) {
			read(client_sockfd, &st, 50);
			printf("%s\n", st);
			sleep(1);
			id++;
			write(client_sockfd, &id, 1);
			close(client_sockfd);
		 	exit(0);
		}
		else {
		 	close(client_sockfd);
		}
	}
	exit(0);

}