// Server helps convert string to upper case

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NO 1996

// Error show function
void error(const char *msg)
{
    perror(msg);
    exit(1);
}


int main(int argc, char *argv[])
{
     // receive string
     char receive[100];

     // sockfd, newsockfd: socket file descriptors
     // portno: Port number
     // n: the return value for the read(), write() call - the number of characters read or written
     int sockfd, newsockfd, portno;

     // clilen: Store the the size of the address of the client
     socklen_t clilen;  

     // buffer: the server reads characters from the socket connection into this buffer
     char buffer[256];

     // sockaddr_in: is a strucure containing an internet address (netinet/in.h)
     struct sockaddr_in serv_addr, cli_addr;
     int n;

     

     // Opening a server socket
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");

    // Set all values in a buffer to zero
     bzero((char *) &serv_addr, sizeof(serv_addr));

     // Get port from argv[1], atoi: convert this form a tring of digits to an integer
     portno = PORT_NO;

     // Set fields to serv_addr
     // htons(): converts a port number in host byte order to 
     // a port number in network byte order
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);

     // The bind() binds a socket to an address
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     // listen(): allows the process to listen on the socket for connections
     listen(sockfd,5);

     // accept() causes the process to block until a client connects to the server
     // it wakes up the process when a connection from a client has been successfully established
     // it returns a new file descriptor
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");

     do
     {
         // bzero(): initializes the buffer, then reads from the socket
         // read from the socket client
         bzero(buffer,256);
         n = read(newsockfd, buffer, 255);
         if (n < 0) error("ERROR reading from socket");
         printf("Here is the message: %s\n",buffer);


         // write to the socket client
         strcpy(receive, buffer);
         int i;
         for (i = 0; i<strlen(receive); i++)
         {
            if (receive[i]>=97 && receive[i]<=128)
            {
                receive[i]-=32;
            }
         }

         n = write(newsockfd, receive,18);
         if (n < 0) error("ERROR writing to socket");
     } while (*receive!= 'q');

     sleep(0.1);

     // Close the connections
     close(newsockfd);
     close(sockfd);
     

     return 0; 
}
