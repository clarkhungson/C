// Lay thong tin cua 1 host

#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	char *host, **names, **addrs;
	struct hostent *hostinfo;

	// Lay thong tin: ten host
	if(argc == 1) {
		char myname[256];
		gethostname(myname, 255); // Lay thong tin: ten host
		host = myname;
	}
	else
		host = argv[1];
	hostinfo = gethostbyname(host);  // Lay thong tin host theo ten
	if(!hostinfo) {
		fprintf(stderr, "Cant get info for host: %s\n", host);
		exit(1);
	}

	// Kieu tra ve hostinfo:
	// struct hostent {
	// 	char *h_name;			// name of the host
	// 	char **h_aliases;		// list of aliases (nicknames)
	// 	int h_addrtype;			// address type
	// 	int h_length;			// length in bytes of the address
	// 	char **h_addr_list;		// list of address )network order)
	// }


	// In ra thong tin
	printf("results for host %s:\n", host);
	printf("Name: %s\n", hostinfo -> h_name);
	printf("Aliases:");
	names = hostinfo -> h_aliases;
	while(*names) {
		printf("%s\n", *names);
		names++;
	}
	printf("\n");
	if(hostinfo -> h_addrtype != AF_INET) {
		fprintf(stderr, "not an IP host!\n");
		exit(1);
	}
	addrs = hostinfo -> h_addr_list;
	while(*addrs) {
		printf("%s\n", inet_ntoa(*(struct in_addr *)*addrs));
		addrs++;
	}
	printf("Address type: %d\n", hostinfo -> h_addrtype);
	printf("Length in bytes of the address: %d\n", hostinfo -> h_length);

	printf("\n");
	exit(0);
}