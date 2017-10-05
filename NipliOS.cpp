#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>

void signal_handler(int no) {
}


int main() {
	char command[50];
	char *token;
	
	
	signal(SIGINT, signal_handler);

	pid_t child;
	
	while(1) {	
		printf("NipliOS>");
		fgets(command, 50, stdin);
		token=strtok(command, " ");

		if (strncmp(token, "PROC",4)==0) {
			printf("Process unfinished \n");
		}
		else if (strncmp(token, "LOAD",4)==0) {
			printf("Loading \n");
		}
		else if (strncmp(token, "MEM",3)==0) {
			printf("Total Memory Used: \n") ;
		}
		else if (strncmp(token, "RESET",5)==0) {
			printf("System Reset \n");
		}
                else if (strncmp(token, "exit",4)==0) {
                        raise(SIGKILL);
                }

	}
	return 0;
}
