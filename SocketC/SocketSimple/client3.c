// Client simple chat

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#define PORT_NO 1996
#define hostname "clark"

//Error show function
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    printf("-------------------You are Client-----------------!\n\n");
    // send string
    char send[100];
    char receive[100];

    // sockfd: socket file descriptor
    // portno: Portnumber of the socket server
    // n: the return value for the read(), write() call
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // buffer: the client read data from a buffer
    char buffer[256];

    // portno: read from argument 2, atoi() is a convert function
    portno = PORT_NO;

    // Opening a client socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // hethostbyname(): get the server from the server's hostname
    // server = gethostbyname(argv[1]);
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Set the fields in serv_addr
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    // Coonect(): connect to the server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    do
    {
        // Message to the server
        printf("Client: ");

        bzero(buffer,256);
        fgets(buffer,255,stdin);
        strcpy(send, buffer);

        // Write a message to the server
        n = write(sockfd,buffer,strlen(buffer));
        if (n < 0) 
             error("ERROR writing to socket");

        // Read the message from server
        bzero(buffer,256);
        n = read(sockfd,buffer,255);
        if (n < 0) 
             error("ERROR reading from socket");
        printf("Server: %s",buffer);

    } while (*send != 'q');

    close(sockfd);
    return 0;
}
