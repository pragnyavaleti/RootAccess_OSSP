#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd1, fd2;
    char message[] = "Hello Server";
    char buffer[100];

    fd1 = open("client_fifo", O_WRONLY);
    fd2 = open("server_fifo", O_RDONLY);

    if (fd1 == -1 || fd2 == -1)
    {
        perror("open");
        exit(1);
    }

    write(fd1, message, strlen(message) + 1);

    printf("Client sent: %s\n", message);

    read(fd2, buffer, sizeof(buffer));

    printf("Server response: %s\n", buffer);

    close(fd1);
    close(fd2);

    return 0;
}
