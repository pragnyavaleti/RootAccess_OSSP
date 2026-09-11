#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    printf("Parent process started\n");
    printf("Parent process ID = %d\n", getpid());
    printf("Parent process ID = %d\n", getppid());

    pid = fork();

    if (pid < 0)
    {
        printf("Process creation failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Child process created\n");
        printf("Child process ID = %d\n", getpid());
        printf("Parent process ID = %d\n", getppid());
        printf("Child process waiting\n");

        sleep(10);

        printf("Child process Running\n");
        printf("Child process Terminated\n");

        exit(0);
    }
    else
    {
        printf("Parent process waiting\n");

        wait(NULL);

        printf("Parent process Resumed\n");
    }

    return 0;
}
