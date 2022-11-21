#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(int argc, char* argv[])
{
	pid_t pid, childpid; 
	pid = fork();
	int status; 
	if (pid == 0){
	    printf("I am child: my pid = %d\n", getpid());
 
	}
	else {
		//printf("I am child: my pid = %d\n", getpid()); 
		childpid = wait(&status);
		printf("I am parent: child pid = %d\n", pid);

	}
}
