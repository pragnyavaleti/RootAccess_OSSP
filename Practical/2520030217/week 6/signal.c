#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig)
{
    if (sig == SIGINT)
        printf("\nSIGINT received\n");

    else if (sig == SIGTERM)
        printf("\nSIGTERM received\n");

    else if (sig == SIGUSR1)
        printf("\nSIGUSR1 received\n");
}

int main()
{
    struct sigaction action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);
    sigaction(SIGUSR1, &action, NULL);

    printf("Process running...\n");
    printf("PID = %d\n", getpid());

    while (1)
    {
        printf("Waiting for signals...\n");
        sleep(3);
    }

    return 0;
}
