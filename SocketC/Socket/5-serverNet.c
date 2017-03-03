// server net

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	// Create socket server and client's descriptor
	int server_sockfd, client_sockfd;
	int server_len, client_len;

	// Create socket server and client's address
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	// Create socket
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// Bind the socket
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = 1996;
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	
	// Create a connection queue and wait for clients
	listen(server_sockfd, 5);
	while(1) {
		char ch;

		printf("server waiting\n");

		// Accept a connection:
		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);

		// Read and write to client on client_sockfd
		read(client_sockfd, &ch, 1);
		ch = ch - 32;
		write(client_sockfd, &ch, 1);
		close(client_sockfd);
	}
	exit(0);
}