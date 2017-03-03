// Client Net


#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	system("clear");
	
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	char ch = 'a';

	//Create a socket for the client
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// Name the socket as agreed with the server
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = 1996;
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