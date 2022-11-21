#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include <readline/history.h>

int standard = 1;

int main(int argc, char* argv[])
{
    pid_t pid;
    int childpid, status, i=0;

    char* cmdline;
    char* opt, *temp;
	char* arr[3];

    while(standard) {
		cmdline = readline("$ ");
    	opt = strtok(cmdline," \n");
		if(!strcmp(opt, "quit")){
			break;
		}


		while(opt!=NULL){
			arr[i] = opt;
			i++;
			opt= strtok(NULL," \n");
		}
		arr[i]=opt;
		else{
			pid =fork();
			if(pid==0){
				execvp(arr[0], arr);
			}	
			childpid = wait(&status);		
			
		}

    return 0;
}
