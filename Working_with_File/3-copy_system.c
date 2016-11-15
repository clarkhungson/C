// copy a file faster

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	system("rm 2-file_out.jpg");
	char block[1024];
	int in, out;
	int nread;

	in = open("2-file_in.jpg", O_RDONLY);
	out = open("2-file_out.jpg", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	while((nread = read(in, block, sizeof(block)) ) > 0)
		write(out, block, nread);

	exit(0);
}