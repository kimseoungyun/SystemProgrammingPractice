#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include <readline/history.h>

int main(int argc, char* argv[])
{
    pid_t pid;
    int childpid, status, i=0;

    char* cmdline;
    char* opt, *temp;
	char* arr[3];
	//char* arr[3];
	int MAX = 100;

	for(int i = 0; i < 3; i++)
		arr[i] = (char*) malloc (sizeof(char)* MAX);

    while(1) {
		cmdline = readline("$ ");
    	opt = strtok(cmdline," \n");
		if(!strcmp(opt, "quit")){
			break;
		}
		int i =0;
		while(opt!=NULL){
			strcpy(arr[i], opt); // strcpy
			i++;
			opt= strtok(NULL," \n");
		}
		arr[i]=opt;

		pid =fork();
		if(pid==0){
			execvp(arr[0], arr);
		}	
		childpid = wait(&status);		
			
		}

    return 0;
}
