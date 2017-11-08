#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include "queue.h"
#include "process_class.h"


void signal_handler(int no) {
}


int main() {
	//Variables for input
	char command[50];
	char *token;
	char *second_arg;
	string arg2;	
	
	//Array for process identification
	process* programs[50];
	
	//Ready and wait queues for CPU
	queue ready_queue;
	queue wait_queue;
	queue io_queue;	

	signal(SIGINT, signal_handler);

	pid_t child;
	
	while(1) {	
		printf("NipliOS>");
		fgets(command, 50, stdin);
		token=strtok(command, " ");
		second_arg=strtok(NULL, " ");

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
		else if (strncmp(token, "RUN", 50)==0) {
			arg2=string (second_arg);
			printf("%s", arg2);

			//process test= process(second_arg);
			//printf("pid=%d", test.getPID());
		}
                else if (strncmp(token, "exit",4)==0) {
                        raise(SIGKILL);
                }

	}
	return 0;
}
