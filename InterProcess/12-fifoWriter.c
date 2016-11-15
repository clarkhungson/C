// Gui message thong qua FIFO
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char mes[] = "This is a message from writer. Nice to see u! ^^";

int main()
{
    int fd;
    char * myfifo = "/home/clark/work/C_programming/InterProcess/myfifo";

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY);
    write(fd, mes, sizeof(mes));
    close(fd);

    /* remove the FIFO */
    //unlink(myfifo);

    return 0;
}
