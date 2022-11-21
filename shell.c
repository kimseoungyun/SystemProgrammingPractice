#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[])
{	
	int childpid, status;
	pid_t pid; 
	pid = fork(); 
	
	if(pid <0){
		perror("fork error");
		exit(0);
	}
	else if(pid == 0){
        execvp(argv[1], argv+1);
		if(execvp(argv[1], argv+1)==-1){
			perror("");
		}
        exit(0);
    }
	else{
		printf("Processing . . .\n"); 
		childpid = wait(&status);
		printf("Completed.\n");
		exit(0);
	}
}
