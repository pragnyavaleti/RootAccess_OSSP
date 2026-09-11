#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd1, fd2;
    char buffer[100];
    int n;

    fd1 = open("source.txt", O_RDONLY);

    if (fd1 == -1)
    {
        perror("open");
        exit(1);
    }

    fd2 = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd2 == -1)
    {
        perror("open");
        close(fd1);
        exit(1);
    }

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        write(fd2, buffer, n);
    }

    close(fd1);
    close(fd2);

    printf("File copied successfully.\n");

    return 0;
}
