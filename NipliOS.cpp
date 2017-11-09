#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
#include "queue.h"
#include "process_class.h"
#include "mem_mgmt.h"

void signal_handler(int no) {
}


int main() {
	//Variables for input
	char command[50];
	char *token;
		
	//Array for process identification
	process programs[20];
	//int for pid assingment
	int pidCounter=0;
	
	//Ready and wait queues for CPU
	queue ready_queue;
	queue wait_queue;
	queue io_queue;	
	
	memory memory;

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
			printf("Total Memory Used: %d MB\n", memory.getMemory()) ;
		}
		else if (strncmp(token, "RESET",5)==0) {
			pidCounter=0;
			printf("System Reset \n");
		}
		else if (strncmp(token, "RUN", 3)==0) {
			cout<<"What process? "<< endl;
			string arg2;
			cin>>arg2;
			process tmp(arg2,pidCounter);
			programs[pidCounter]=tmp;
			pidCounter++;
			
		}
                else if (strncmp(token, "exit",4)==0) {
                        raise(SIGKILL);
                }

	}
	return 0;
}
