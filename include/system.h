#include <vector>

#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#include "../include/process_class.h"
#include "../include/mem_mgmt.h"
#include "../include/rr.h"
#include "../include/queue.h"

using namespace std;

class system{
	private:
		sem_t semaphore;

		vector<process*> WAIT;
		vector<process*> NEW;
		vector<process*> READY;
		vector<process*> EXIT;

		queue ready_queue;
		queue fore_ground;
		queue back_ground;

		int counter = 0;

		processor processor1;
		memory mainmem;

		rr ready(25);
		rr fore(50);

		int start=0;
		
		struct cpuThreadParams params;
		void *cpu_processing(void *);


	public:
		struct cpuThreadParams {
			queue* one;
			queue* two;
			queue* three;

			memory* main;

			rr* first;
			rr* second;

			int* start;
		}
		int spawn(string);
		int kill(process*,string);
		int addReady(process*);
		int requestIO(process*);
		int useIO(process*);
		int freeIO(process*);
		process* next();
		int run(int,system*);
};
