// client socket

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	system("clear");
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch = 'a';

	//Create a socket for the client
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	// Name the socket as agreed with the server
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);

	//Connect your socket to the server's socket
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if(result == -1) {
		perror("oops: client1");
		exit(1);
	}

	//You can read and write via sockfd
	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);
	printf("char from server = %c\n", ch);
	close(sockfd);
	exit(0);
}