#ifndef SYSTEM_H
#include <vector>

#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


#ifndef CPU_H
#include "cpu.h"
#endif

#ifndef QUEUE_H
#include "queue.h"
#endif

#ifndef RR_H
#include "rr.h"
#endif

#ifndef PROCESS_H
#include "process_class.h"
#endif

#ifndef MEM_H
#include "mem_mgmt.h"
#endif

#endif


//class processor;

using namespace std;

class system{
	public:
		struct cpuThreadParams {
			queue* one;
			queue* two;
			queue* three;

			memory* main;

			rr* first;
			rr* second;

			int* start;
		};
		int spawn(string);
		int kill(process*,string);
		int addReady(process*);
		int requestIO(process*);
		int useIO(process*);
		int freeIO(process*);
		process* next();
		int run(int,system*);

		void resetQueue(queue*);

	private:
		sem_t semaphore;

		vector<process*> WAIT;
		vector<process*> NEW;
		vector<process*> READY;
		vector<process*> EXIT;

		int cpu1;
		int cpu2;
		int cpu3;
		int cpu4;

		queue ready_queue;
		queue fore_ground;
		queue back_ground;

		int counter = 0;

		processor* processor1;

		rr* ready;
		rr* fore;

		int start=0;
		
		struct cpuThreadParams params;
		static void cpu_processing(void *);
		memory mainmem;
};
#define SYSTEM_H
