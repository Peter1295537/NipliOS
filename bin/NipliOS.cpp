#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include "../include/rr.h"


sem_t semaphore;

void signal_handler(int no) {
}


struct cpuThreadParams {
	queue* one;
        queue* two;
        queue* three;


        //CPU
        processor* cpu;

        //Memory
        memory* main;

        //Scheduler
        rr* first;
        rr* second;
	
};


void *cpu_processing(void *input) {
        
	struct cpuThreadParams* params=(cpuThreadParams*)input;        
	int tmp;
	int turn_counter=0;
	while (1) {	
		sem_wait(&semaphore);			

		if (turn_counter<7 && params->one->current()>-1) {
       	                params->first->swap(params->one,params->cpu, params->main);
               	}

               	else if (turn_counter>=7 && turn_counter<=8) {
			if (params->two->current()>-1) {
                       		params->second->swap(params->two, params->cpu, params->main);
			}
       	        }
               	else if (turn_counter==9 && params->three->current()>-1) {
                       	params->first->fcfs(params->three,params->cpu, params->main);
			cout<<"ACK";
               	}
		if (params->one->current()!=-1) {
			if (params->main->getProcess((params->one->current())).getTimeElapsed()>5000) {
				tmp=params->one->remove();
               			params->two->insert(tmp);
       			}
		}
      	 	
		if (params->two->current()!=-1) {	
			if (params->main->getProcess((params->two->current())).getTimeElapsed()>10000) {
				tmp=params->two->remove();
        	       		params->three->insert(tmp);
      			}
		}
		turn_counter++;
		if (turn_counter>9) {
			turn_counter=0;
		}
	        sem_post(&semaphore);
		sleep(1);
	}
}



int main() {
	//Variables for input
	char command[50];
	char *token;
	
	struct cpuThreadParams params;
	
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
	rr ready(25);
	rr fore(50);
	

	signal(SIGINT, signal_handler);

	//Threading Struct Intializations
        sem_post(&semaphore);
	
	params.one=&ready_queue;
	params.two=&fore_ground;
	params.three=&back_ground;
	params.cpu=&processor1;
	params.main=&mainmem;
	params.first=&ready;
	params.second=&fore;

	pthread_t threads[2];
	int cpu1= pthread_create(&threads[1], NULL, cpu_processing, (void*) &params);
	int cpu2= pthread_create(&threads[1], NULL, cpu_processing, (void*) &params);

		
	while(1) {
		
//Input parsing	
		printf("\nNipliOS>");
		fgets(command, 50, stdin);
		token=strtok(command, " ");

		if (strncmp(token, "PROC",4)==0) {
			sem_wait(&semaphore);
			printf("Process unfinished \n");
			cout<<ready_queue.current();
        		sem_post(&semaphore);

		}
		else if (strncmp(token, "LOAD",4)==0) {
        		sem_wait(&semaphore);
	                printf("Loading \n");
			sem_post(&semaphore);
		}
		else if (strncmp(token, "MEM",3)==0) {
	
			sem_wait(&semaphore);
			printf("Total Memory Used: %d MB\n", mainmem.getMemory());
			sem_post(&semaphore);
		}
		else if (strncmp(token, "RESET",5)==0) {
			sem_wait(&semaphore);
			mainmem.resetProcesses();
			printf("System Reset, all processes terminated \n");
			sem_post(&semaphore);
		}
		else if (strncmp(token, "EXE", 3)==0) {
			string filename;
			sem_wait(&semaphore);
			cout<<"Select process to execute: "<< endl;
			cin>>filename;
			mainmem.createProcess(filename);
			ready_queue.insert(counter); 
			sem_post(&semaphore);

			counter++;	
		}
                else if (strncmp(token, "exit",4)==0 || strncmp(token, "EXIT",4)==0) {
			raise(SIGKILL);
                }
	}
	return 0;
}
