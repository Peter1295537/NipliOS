#include <'../include/system.h'>

using namespace std;

system::system(){
	sem_post(&semaphore);

	params.one=&ready_queue;
	params.two=&fore_ground;
	params.three=&back_ground;
	params.main=&mainmem;
	params.first=&ready;
	params.second=&fore;
	params.start=&start;

	pthread_t threads[4];

	cpu1= pthread_create(&threads[0], NULL, &system::cpu_processing, (void*) &params);
	cpu2= pthread_create(&threads[1], NULL, &system::cpu_processing, (void*) &params);
	cpu3= pthread_create(&threads[2], NULL, &system::cpu_processing, (void*) &params);
	cpu4= pthread_create(&threads[3], NULL, &system::cpu_processing, (void*) &params);
}

int system::spawn(string filename){
	//NEED ERROR CHECKING HERE
	process tmp(filename, mainmem.getPidCounter());
	NEW.push_back(&tmp);

	return 0;
}
int system::requestIO(process* p){
	WAIT.push_back(p);

	return 0;

}
/*int system::addReady(process* p){
	READY.push_back(p);

	return 0;
}*/
static void system::cpu_processing(void *input) {

	struct cpuThreadParams* params=(cpuThreadParams*)input;
	int tmp;
	int turn_counter=0;
	int flag;
	processor processor1;
	processor* cpu=&processor1;
	while (1) {

		sem_wait(&semaphore);
		flag=*params->start;
		if (flag==1) {
			if (turn_counter<7 && params->one->current()>-1) {
       	                	params->first->swap(params->one,cpu, params->main);
               		}

               		else if (turn_counter>=7 && turn_counter<=8) {
				if (params->two->current()>-1) {
                       			params->second->swap(params->two, cpu, params->main);
				}
       	        	}
               		else if (turn_counter==9 && params->three->current()>-1) {
                       		params->first->fcfs(params->three,cpu, params->main);
               		}
			if (turn_counter<7 && params->one->current()==-1) {
				if (params->two->current()>-1) {
					params->second->swap(params->two, cpu, params->main);
				}
			}
			if (turn_counter<9 && params->one->current()==-1) {
                        	if (params->two->current()==-1 && params->three->current()>-1) {
                               		params->first->fcfs(params->three,cpu, params->main);
                        	}
                	}
			if (params->one->current()!=-1) {
				if (params->main->getProcess((params->one->current())).getTimeElapsed()>2500) {
					tmp=params->one->remove();
               				params->two->insert(tmp);
       				}
			}

			if (params->two->current()!=-1) {
				if (params->main->getProcess((params->two->current())).getTimeElapsed()>5000) {
					tmp=params->two->remove();
        	       			params->three->insert(tmp);
      				}
			}
			if (turn_counter>9) {
				turn_counter=0;
			}
		}
		sem_post(&semaphore);
		turn_counter++;
		sleep(1);
	}
}
void system::resetQueue(queue* input){
	while(input->current()>-1){
		input->remove();
	}
}
