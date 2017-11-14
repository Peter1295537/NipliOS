#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
#include "../include/rr.h"

void signal_handler(int no) {
}

int main() {
	//Variables for input
	char command[50];
	char *token;
		
	//Ready and wait queues for CPU
	queue ready_queue;
	queue wait_queue;
	queue io_queue;
	int counter=0;	

	//CPU
	processor processor1;
	
	//Memory
	memory mainmem;
	
	//Scheduler
	rr shortterm(16);


	signal(SIGINT, signal_handler);

	pid_t child;
	
	while(1) {	
		printf("\nNipliOS>");
		fgets(command, 50, stdin);
		token=strtok(command, " ");

		if (strncmp(token, "PROC",4)==0) {
			printf("Process unfinished \n");
		}
		else if (strncmp(token, "LOAD",4)==0) {
			printf("Loading \n");
		}
		else if (strncmp(token, "MEM",3)==0) {
			printf("Total Memory Used: %d MB\n", mainmem.getMemory()) ;
		}
		else if (strncmp(token, "RESET",5)==0) {
			mainmem.resetProcesses();
			printf("System Reset, all processes terminated \n");
		}
		else if (strncmp(token, "EXE", 3)==0) {
			string filename;
			cout<<"Select process to execute: "<< endl;
			cin>>filename;
			mainmem.createProcess(filename);
			ready_queue.insert(counter);
			counter++;
			shortterm.swap(&ready_queue, &processor1, &mainmem);	
		}
                else if (strncmp(token, "exit",4)==0 || strncmp(token, "EXIT",4)==0){
                        raise(SIGKILL);
                }

	}
	return 0;
}
