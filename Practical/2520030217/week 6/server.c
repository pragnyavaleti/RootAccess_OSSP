#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fd1, fd2;
    char buffer[100];
    char response[100];

    mkfifo("client_fifo", 0666);
    mkfifo("server_fifo", 0666);

    fd1 = open("client_fifo", O_RDONLY);
    fd2 = open("server_fifo", O_WRONLY);

    if (fd1 == -1 || fd2 == -1)
    {
        perror("open");
        exit(1);
    }

    read(fd1, buffer, sizeof(buffer));

    printf("Server received: %s\n", buffer);

    strcpy(response, "Message processed by server");

    write(fd2, response, strlen(response) + 1);

    close(fd1);
    close(fd2);

    unlink("client_fifo");
    unlink("server_fifo");

    return 0;
}
