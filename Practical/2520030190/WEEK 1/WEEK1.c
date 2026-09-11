#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
pid_t pid;
pid = fork();
if(pid < 0){
printf("Process failed\n");
exit(1);
}
else if(pid == 0){
printf("Child process\n");
printf("Child process id = %d\n", getpid());
printf("Parent process id = %d\n", getppid());
execl("/bin/ls","ls","-l",NULL);
printf("exec failed\n");
exit(1);
}
else{
printf("Parent process\n");
printf("Parent process id = %d\n", getpid());
wait(NULL);
printf("Child process Finished\n");
}
return 0;
}
