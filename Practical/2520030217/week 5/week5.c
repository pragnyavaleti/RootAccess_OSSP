#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    int fd[2];
    pid_t pid;
    char buffer[100];
    char data[] = "Data produced by parent";
    clock_t start, end;

    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }

    if (pid == 0)
    {
        close(fd[1]);

        start = clock();

        read(fd[0], buffer, sizeof(buffer));

        end = clock();

        printf("Child consumed: %s\n", buffer);
        printf("Communication time: %f seconds\n",
               (double)(end - start) / CLOCKS_PER_SEC);

        close(fd[0]);
    }
    else
    {
        close(fd[0]);

        write(fd[1], data, strlen(data) + 1);

        printf("Parent produced: %s\n", data);

        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
