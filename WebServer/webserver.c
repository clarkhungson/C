#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SERVER_ADDRESS "192.168.100.65"
char webpage[] = 
"HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<!DOCTYPE html>\r\n"
"<html><head><title>Clark's Webpage</title>\r\n"
//"<style>body { background-color: #00FF00 }</style></head>\r\n"
"<body background=\"back.jpg\">"
"<body><center>"
"<h1>Hello world! This is my webpage..</h1><hr></br></br>\r\n"
"<marquee scrollamount=\"10\" behavior=\"alternate\"><img src=\"girl.jpg\"><br></marquee>"
"<a href=\"https://www.youtube.com/watch?v=1F2fsep_Tn4&feature=share\">Tran Thuy Duong VTV4</a>"
//"<head><link rel=\"icon\" type=\"image/ico\" href=\"bird.ico\"/> </head>"
//"<iframe width=\"420\" height=\"315\" src=\"https://www.youtube.com/watch?v=3AtDnEC4zak\"> </iframe>"
"<h2><i><b></br></br></br>Have a nice day! ^^</b></i></h2>"
"</center></body></html>\r\n";

int main(int argc, char *argv[])
{
	// File add cua server va client
	struct sockaddr_in server_addr, client_addr;
	socklen_t sin_len = sizeof(client_addr);
	// File descriptor cua server va client
	int fd_server, fd_client;
	char buf[2048];
	int fdimg;
	int on = 1;

	// Tao socket server
	fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_server < 0)
	{
		perror("socket");
		exit(1);
	}
	// Set option cho socket server
	setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));

	// Set dia chi cho server
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	server_addr.sin_port = htons(80);

	// Gan server socket voi dia chi
	if(bind(fd_server, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		perror("bind");
		close(fd_server);
	}

	// Server listen cac ket noi
	if(listen(fd_server, 10) == -1)
	{
		perror("listen");
		close(fd_server);
		exit(1);
	}

	// 
	while(1)
	{
		fd_client = accept(fd_server, (struct sockaddr *) &client_addr, &sin_len);
		if(fd_client == -1)
		{
			perror("Connection failed... ");
			continue;
		}
		printf("Got client connection...\n");
		if(!fork())
		{
			/*child process */
			close(fd_server);
			memset(buf, 0, 2048);
			read(fd_client, buf, 2047);
			printf("%s\n", buf);
			if(!strncmp(buf, "GET /favicon.ico", 13))
			{
				fdimg = open("favicon.ico", O_RDONLY);
				sendfile(fd_client, fdimg, NULL, 4000);
				close(fdimg);
			}
			else if(!strncmp(buf, "GET /girl.jpg", 13))
			{
				fdimg = open("girl.jpg", O_RDONLY);
				sendfile(fd_client, fdimg, NULL, 70000);
				close(fdimg);
			}
			else if(!strncmp(buf, "GET /back.jpg", 13))
			{
				fdimg = open("back.jpg", O_RDONLY);
				sendfile(fd_client, fdimg, NULL, 80000);
				close(fdimg);
			}
			else 
				write(fd_client, webpage, sizeof(webpage) - 1);
			close(fd_client);
			printf("closing...\n");
			exit(0);

		}
		close(fd_client);
	}

	return 0;
}