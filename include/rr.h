#include <stdlib.h>
#include "process_class.h"
#include "queue.h"
#include "mem_mgmt.h"
#include "cpu.h"

class rr{
	public:
		int quantum;
		rr(int q);
		void swap(queue* x, processor* cpu, memory* main);
		int getQuantum();
		
				
};
