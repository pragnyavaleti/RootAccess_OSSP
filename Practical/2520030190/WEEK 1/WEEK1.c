Develop a C program that demonstrates how a Linux operating system executes a command entered by a user that 
1. Accept a Linux command as input. 
2. Create a child process using fork().
3. Execute the command in the child process using an appropriate exec() system call.
4. Allow the parent process to wait for the child using wait (). 
5. Display the Process ID (PID) of both parent and child processes.

Using Linux terminal commands (uname, lscpu, lsblk, ps, top), investigate the relationship between hardware resources and operating system services. 
Prepare a report explaining how the OS abstracts CPU, memory, storage, and I/O devices. 



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
