#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	// tao nunamed socket server
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	// dat ten cho socket
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("192.168.100.65");
	server_address.sin_port = 1234;
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	// tao queue va doi client ket noi
	listen(server_sockfd, 5);
	while(1){
		char ch;
		printf("\nserver waiting...\n");
	
	// chap nhan ket noi
	client_len = sizeof(client_address);
	client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
	// doc va ghi vao client
	read(client_sockfd, &ch,1);
	ch++;
	write(client_sockfd, &ch,1);
	close(client_sockfd);
	}
}
