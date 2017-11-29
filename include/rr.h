#ifndef RR_H
#define RR_H
//#include <stdlib.h>
#include "queue.h"
#include "mem_mgmt.h"
#include "cpu.h"

class rr{
	public:
		int quantum;
		rr(int q);
		void fcfs(queue* x, processor* cpu, memory* main);
		void swap(queue* x, processor* cpu, memory* main);
		int getQuantum();
		
				
};
#endif
