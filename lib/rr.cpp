#include <stdlib.h>
#include "../include/rr.h"
#include <iostream>


rr::rr(int q) {
	quantum=q;
}

void rr::swap(queue* x, processor* cpu, memory* main,io_device_mgr* iodm) {
	int tmp;
	process* input;
	tmp=x->remove();
	input=main->getProcess(tmp);	
	cpu->load(input);
	cpu->run(quantum,iodm);
	if (input->getTimeRemaining()>0 && input->getState()!=process::state_t(WAIT)) {
                input->setState(process::state_t(READY));        
		x->insert(tmp);
        }
}


void rr::fcfs(queue* x, processor* cpu, memory* main,io_device_mgr* iodm) {
        int tmp;
        process* input;
        tmp=x->current();
        input=main->getProcess(tmp);
        cpu->load(input);
        cpu->run(100,iodm);

        if (input->getTimeRemaining()<=0) {
                x->remove();
        } 

}

	



int rr::getQuantum() {
	return quantum;
}
