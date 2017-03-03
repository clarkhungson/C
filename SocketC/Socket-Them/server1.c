#include <stdio.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <arpa/inet.h>

#define PORT 8081
#define CLIENT_PORT 1235
#define LEN  1024

struct threadArg{
	int sock;
	struct sockaddr_in serAdd;
};

char buffer[LEN];
char recvBuffer[LEN];

void *sendThreadFunc(void* arg){
	int sock = ((struct threadArg *) arg) -> sock;
	struct sockaddr_in serAdd = ((struct threadArg *) arg) -> serAdd;
	int addLen = sizeof(serAdd);
	while(1){
		printf("%s","Server: " );
		fgets(buffer,1023,stdin);
		printf("%s",buffer);
		sendto(sock, buffer, LEN, 0, (struct sockaddr*) &serAdd, addLen);
	}
}

void *recvThreadFunc(void *arg){
	int sock = ((struct threadArg *) arg) -> sock;
	struct sockaddr_in serAdd = ((struct threadArg *) arg) -> serAdd;
	int addLen = sizeof(serAdd);
	while(1){
		recvfrom(sock, recvBuffer, LEN, 0, (struct sockaddr*) &serAdd, &addLen);
		printf("%s","Client: " );
		printf("%s",recvBuffer);
	}
}
int main(){
	pthread_t sendThread,recvThread;

	int sock, addLen;

	struct sockaddr_in serAdd, cliAdd;
	sock = socket(AF_INET, SOCK_DGRAM, 0);

	memset((char *) &serAdd, '\0', sizeof(serAdd));
	serAdd.sin_family = AF_INET;
	serAdd.sin_port   = htons(PORT);
	serAdd.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sock, (struct sockaddr*) &serAdd, sizeof(serAdd));

	memset((char *) &cliAdd, '\0', sizeof(cliAdd));
	cliAdd.sin_family = AF_INET;
	cliAdd.sin_port   = htons(CLIENT_PORT);
	cliAdd.sin_addr.s_addr = htonl(INADDR_ANY);

	struct threadArg *arg;
	arg = (struct threadArg *)malloc(sizeof(struct threadArg));
	arg -> sock = sock;
	arg -> serAdd = cliAdd;

	pthread_create(&recvThread, NULL, recvThreadFunc, (void *) arg);
	pthread_create(&sendThread, NULL, sendThreadFunc, (void *) arg);
	pthread_join(sendThread, NULL);
	pthread_join(recvThread, NULL);

	close(sock);
}