// Tao ra 1 file voi quyen: read (owner), execute (others)

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int a = open("1-creteFile.txt", O_CREAT, S_IRUSR|S_IXOTH);
	return 0;
}