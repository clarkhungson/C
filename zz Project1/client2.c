#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	char ch = 'A';

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family =AF_INET;
	address.sin_addr.s_addr = inet_addr("192.168.100.65");
	address.sin_port = 8888;
	len = sizeof(address);
	// ket noi socket den server
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if(result == -1){
		perror("opps:client1");
		exit(1);
	}
	// doc va ghi thong qua sockfd
	write(sockfd, &ch,1);
	read(sockfd, &ch,1);
	printf("char from server = %c\n", ch);
	close(sockfd);
	exit(0);
	
}