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
	queue fore_ground;
	queue back_ground;

	queue wait_queue;
	queue io_queue;
	int counter=0;	

	//CPU
	processor processor1;
	
	//Memory
	memory mainmem;
	
	//Scheduler
	int turn_counter=0;
	rr ready(25);
	rr fore(50);
	
	//Degradation counter
	int tmp;

	signal(SIGINT, signal_handler);

	pid_t child;
	
	while(1) {
		
//Input parsing	
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
		}
                else if (strncmp(token, "exit",4)==0 || strncmp(token, "EXIT",4)==0){
                        raise(SIGKILL);
                }
//Decides which queue to send to processer

		if (mainmem.getProcess((ready_queue.current())).getTimeElapsed()>5000) {
			tmp=ready_queue.remove();
			fore_ground.insert(tmp);
		}
		if (mainmem.getProcess((fore_ground.current())).getTimeElapsed()>10000) {
                        tmp=fore_ground.remove();
                        back_ground.insert(tmp);
                }

		if (turn_counter<7) {
			ready.swap(&ready_queue, &processor1, &mainmem);
			turn_counter++;
		}
		else if (turn_counter>=7 && turn_counter<=8) {
			fore.swap(&fore_ground, &processor1, &mainmem);
			turn_counter++;
		}
		else if (turn_counter=9) {
			turn_counter=0;
			ready.fcfs(&back_ground,&processor1, &mainmem);
		}
		
	}
	return 0;
}
