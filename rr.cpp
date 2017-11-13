#include <stdlib.h>
#include "rr.h"
#include <iostream>


rr::rr(int q) {
	quantum=q;
}

void rr::swap(queue* x, processor* cpu, memory* main) {
	int tmp;
	process* input;
	while(x->current() !=-1) {
		tmp=x->remove();
		input=&(main->getProcess(tmp));
		cpu->load(input);
		cpu->calculate(quantum);
		cpu->yield(input);
		if (input->getTimeRemaining()>0) {
			x->insert(tmp);
		}
	}
	


}

int rr::getQuantum() {
	return quantum;
}
