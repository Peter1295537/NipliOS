#include <stdlib.h>
#include "../include/rr.h"
#include <iostream>


rr::rr(int q) {
	quantum=q;
}

void rr::swap(queue* x, processor* cpu, memory* main) {
	int tmp;
	process* input;
	tmp=x->remove();
	input=&(main->getProcess(tmp));
	cpu->load(input);
	cpu->calculate(quantum);
	cpu->yield(input);
	if (input->getTimeRemaining()>0) {
                        x->insert(tmp);
        }
}


void rr::fcfs(queue* x, processor* cpu, memory* main) {
        int tmp;
        process* input;
        tmp=x->current();
        input=&(main->getProcess(tmp));
        cpu->load(input);
        cpu->calculate(50);
        cpu->yield(input);

        if (input->getTimeRemaining()<=0) {
                        x->remove();
        }

}

	



int rr::getQuantum() {
	return quantum;
}
