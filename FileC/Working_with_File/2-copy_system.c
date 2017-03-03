// copy a file

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	char c;
	int in, out;
	in = open("2-file_in.jpg", O_RDONLY);
	out = open("2-file_out.jpg", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	while(read(in, &c,1) == 1)
		write(out, &c, 1);

	exit(0);
}