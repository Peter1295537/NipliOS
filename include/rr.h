//#include <stdlib.h>
#ifndef QUEUE_H
#include "queue.h"
#endif

#ifndef MEM_H
#include "mem_mgmt.h"
#endif

#ifndef CPU_H
#include "cpu.h"
#endif

#ifndef IODEVICE_H
#include "iodevice.h"
#endif

class processor;
class rr{
	public:
		int quantum;
		rr(int q);
		void fcfs(queue* x, processor* cpu, memory* main,io_device_mgr* iodm);
		void swap(queue* x, processor* cpu, memory* main,io_device_mgr* iodm);
		int getQuantum();
		
				
};
#define RR_H
