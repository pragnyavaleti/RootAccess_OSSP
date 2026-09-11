#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t c1, c2, c3;

    c1 = fork();

    if(c1 == 0){
        sleep(3);
        printf("Child 1 finished\n");
        exit(0);
    }

    c2 = fork();

    if(c2 == 0){
        sleep(2);
        printf("Child 2 finished\n");
        exit(0);
    }

    c3 = fork();

    if(c3 == 0){
        sleep(3);
        printf("Child 3 finished\n");
        exit(0);
    }

    printf("Parent waiting for child\n");
    wait(NULL);

    printf("Parent waiting for child 1\n");
    waitpid(c1, NULL, 0);

    printf("Parent waiting for child 2\n");
    waitpid(c2, NULL, 0);

    printf("All Childern finished\n");

    return 0;
}
