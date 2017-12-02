#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <string>
#include <string.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <vector>

#include "../include/rr.h"
//#include "../include/iodevice.h"


sem_t semaphore;

void signal_handler(int no) {
}


struct cpuThreadParams {
	queue* one;
        queue* two;
        queue* three;


        //Memory
        memory* main;

        //Scheduler0
        rr* first;
        rr* second;

	//io device manager
	io_device_mgr* iodm;

	//EXE Flag
	int* start;

	//Number of Cycles
	int* num_cycles;
	int cycles;
	
	
};

void *manage_io(void *input) {
	struct cpuThreadParams* params=(cpuThreadParams*)input;        
	io_device_mgr* iodm;	
	iodm=params->iodm;
	while(1){
		if(iodm->go){
			for(int i=0;i<iodm->getSize();i++){
				process* p = iodm->getProcAtIndex(i);
				if(iodm->allocateIO(p)==0){
					p->setState(process::state_t(READY));		
					params->one->insert(p->getPID());

				}
			}			
			iodm->go=false;
		}
	}
}

void *cpu_processing(void *input) {
        
	struct cpuThreadParams* params=(cpuThreadParams*)input;        
	int tmp;
	int turn_counter=0;
	int flag;
	int max;
	
	int cycles;
	int begin;
	int end;
	
	processor processor1;
	processor* cpu=&processor1;
	process* placeholder;
	while (1) {
		cycles=params->cycles;	
		sem_wait(&semaphore);			
		flag=*params->start;
		max=*params->num_cycles;
		if (flag==0) {
			params->cycles=0;
		}
		if (flag==1) {
			if (cycles<max) {	
				if (turn_counter<7 && params->one->current()>-1) {
					placeholder=params->main->getProcess((params->one->current()));
					begin=placeholder->getTimeRemaining();
       	                		params->first->swap(params->one,cpu, params->main, params->iodm);
					end=placeholder->getTimeRemaining();
					cycles=cycles+(begin-end);
               			}

               			else if (turn_counter>=7 && turn_counter<=8) {
					if (params->two->current()>-1) {
						placeholder=params->main->getProcess((params->two->current()));
	                                        begin=placeholder->getTimeRemaining();
                       				params->second->swap(params->two, cpu, params->main, params->iodm);
						end=placeholder->getTimeRemaining();
	                                        cycles=cycles+(begin-end);
					}
       	        		}
               			else if (turn_counter==9 && params->three->current()>-1) {
					placeholder=params->main->getProcess((params->three->current()));
                                        begin=placeholder->getTimeRemaining();	
                       			params->first->fcfs(params->three,cpu, params->main, params->iodm);
					end=placeholder->getTimeRemaining();
                                        cycles=cycles+(begin-end);

               			}
				if (turn_counter<7 && params->one->current()==-1) {
					if (params->two->current()>-1) {
        	                                placeholder=params->main->getProcess((params->two->current()));
	                                        begin=placeholder->getTimeRemaining();
						params->second->swap(params->two, cpu, params->main, params->iodm);
						end=placeholder->getTimeRemaining();
	                                        cycles=cycles+(begin-end);
					}
				}
				if (turn_counter<9 && params->one->current()==-1) {
                        		if (params->two->current()==-1 && params->three->current()>-1) {   
                                                placeholder=params->main->getProcess((params->three->current())); 
						begin=placeholder->getTimeRemaining();
						params->first->fcfs(params->three,cpu, params->main, params->iodm);
                                                end=placeholder->getTimeRemaining();
                                                cycles=cycles+(begin-end);

                        		}
                		}
				if (params->one->current()!=-1) {
					if (params->main->getProcess((params->one->current()))->getTimeElapsed()>2500) {
						tmp=params->one->remove();
               					params->two->insert(tmp);
       					}
				}
				if (params->two->current()!=-1) {	
					if (params->main->getProcess((params->two->current()))->getTimeElapsed()>5000) {
						tmp=params->two->remove();
        	       				params->three->insert(tmp);
      					}
				}
                                if (params->one->current()==-1 && params->two->current()==-1) {
					if (params->three->current()==-1) {	
						cycles++;
					}
				}

				if (turn_counter>9) {
					turn_counter=0;
				}
/* Maybe one day this will work
				if (cycles==max) {
					cout<<"Finished running: "<< cycles<< " cycles"<<endl; 
				}
*/
			}

		}
		params->cycles=cycles;
		sem_post(&semaphore);
		turn_counter++;
		sleep(1);
	}
}

void resetQueue(queue* input) {
	while(input->current()>-1){
		input->remove();
	}
}

void printProcs(int counter, memory mem) {
	for (int i=0;i<counter;i++) {
		cout<<"PID: "<<mem.getProcess(i)->getPID()<<endl;
		cout<<"Memory Used: " <<mem.getProcess(i)->getMemory()<<endl;
		if (mem.getProcess(i)->getState()==0)
			cout<<"State: NEW"<<endl;
		else if  (mem.getProcess(i)->getState()==1)
			cout<<"State: READY" <<endl;
		else if (mem.getProcess(i)->getState()==2)
			cout<<"State: RUN"<<endl;
		else if (mem.getProcess(i)->getState()==3)
			cout<<"State: WAIT"<<endl;
		else if (mem.getProcess(i)->getState()==4)
			cout<<"State: EXIT"<<endl;
		cout<<"Time Elapsed: "<< mem.getProcess(i)->getTimeElapsed()<<endl;
		cout<<"Time Remaining: "<<mem.getProcess(i)->getTimeRemaining()<<endl;
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
	
	//Memory
	memory mainmem;

	//Scheduler
	rr ready(25);
	rr fore(50);

	//io device manager
	vector<process*> WAIT;
	vector<string> output_buffer;
	io_device_mgr iodm(&WAIT,&output_buffer);
	

	signal(SIGINT, signal_handler);
	int start=0;
	
	int num_cycles=0;
	int cycles=0;
	
	//Threading Struct Intializations
        sem_post(&semaphore);
	
	params.one=&ready_queue;
	params.two=&fore_ground;
	params.three=&back_ground;
	params.main=&mainmem;
	params.first=&ready;
	params.second=&fore;
	params.start=&start;
	params.iodm=&iodm;
	params.num_cycles=&num_cycles;
	params.cycles=cycles;
	

	pthread_t threads[5];
	int cpu1= pthread_create(&threads[0], NULL, cpu_processing, (void*) &params);
	int cpu2= pthread_create(&threads[1], NULL, cpu_processing, (void*) &params);
        int cpu3= pthread_create(&threads[2], NULL, cpu_processing, (void*) &params);
        int cpu4= pthread_create(&threads[3], NULL, cpu_processing, (void*) &params);
	int iom = pthread_create(&threads[4], NULL, manage_io, (void*) &params);
		
	while(1) {
		
//Input parsing	
		printf("\nNipliOS>");
		fgets(command, 50, stdin);
		token=strtok(command, " ");

		if (strncmp(token, "proc",4)==0 || strncmp(token, "PROC",4)==0) {
			sem_wait(&semaphore);
			printf("Processes unfinished queue one: %d\n", ready_queue.getSize());
			printf("Processes unfinished queue two: %d\n", fore_ground.getSize());
			printf("Processes unfinished queue three: %d\n", back_ground.getSize());
			printf("Processes unfinished wait queue: %d\n", WAIT.size());
        		cout<<"\n";
			printProcs(counter, mainmem);
			sem_post(&semaphore);

		}
		else if (strncmp(token, "load",4)==0 || strncmp(token, "LOAD",4)==0) {
			string filename;
			string front="../data/";
                        sem_wait(&semaphore);
			sleep(0.5);
                        cout<<"Select process to load: "<< endl;
                        cin>>filename;
                        mainmem.createProcess(front+filename, counter);
                        ready_queue.insert(counter);
                        sem_post(&semaphore);

                        counter++;

		}
		else if (strncmp(token, "mem",3)==0 || strncmp(token, "MEM",3)==0) {
			sem_wait(&semaphore);
			printf("Total Memory Used: %d MB\n", mainmem.getUsedMemory());
			printf("Available Memory: %d MB\n", mainmem.getFreeMemory());
			sem_post(&semaphore);
		}
		else if (strncmp(token, "reset", 5)==0 || strncmp(token, "RESET",5)==0) {
			sem_wait(&semaphore);
			start=0;
			num_cycles=0;
			params.cycles=0;
			mainmem.resetProcesses();
			resetQueue(&ready_queue);
			resetQueue(&fore_ground);
			resetQueue(&back_ground);
			resetQueue(&wait_queue);
			resetQueue(&io_queue);
			printf("System Reset, all processes terminated \n");
			sem_post(&semaphore);
			counter=0;
		}
		else if (strncmp(token, "exe",3)==0 ||strncmp(token, "EXE", 3)==0) {
			int tmp;
			sem_wait(&semaphore);
			cout<<"Enter number of cycles:"<< endl;
			cin>>tmp;
			num_cycles=num_cycles+tmp;
			printf("Executing loaded programs");
			start=1;	
			sem_post(&semaphore);
	
		}
		else if (strncmp(token,"man", 3)==0 || strncmp(token, "MAN", 3)==0) {
			int out=system("cat ../README.md");		
		}
		else if (strncmp(token,"gen",3)==0 || strncmp(token, "GEN", 3)==0) {
			char buffer [30];
			cout<<"Enter number of processes: "<<endl;
			int output=system("python ../data/procGen.py");
			cout<<"Created Processes"<<endl;
		}
		else if (strncmp(token,"stop", 4)==0 || strncmp(token, "STOP",4)==0) {
			sem_wait(&semaphore);
			start=0;
			cout<<"Execution stopped"<<endl;
			sem_post(&semaphore);
		}
		else if (strncmp(token, "exit",4)==0 || strncmp(token, "EXIT",4)==0) {
			raise(SIGKILL);
    		}
	}
	return 0;
}
