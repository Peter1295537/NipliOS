//#include "../include/queue.h"
#include "../include/cpu.h"
#include <random>

processor::processor(){
	preempt=true;

}
int processor::load(process* _new){
	if(preempt){
		current = _new;
		current->setState(process::state_t(RUN));
		return 0;
	}
	else{
		return 1;
	}
}
int processor::run(int cycles,io_device_mgr* iodm){
	string inst = current->nextInstruction();
	if(inst.compare(0,9,"CALCULATE")==0){
		if(current->currentLeft>0){
			calculate(cycles,iodm);
		}
		else{
			current->currentLeft=stoi(inst.substr(10));
			calculate(cycles,iodm);
		}
	}

	if(inst.compare("IO")==0){
		if(!current->hasResources){
			std::default_random_engine generator;
			std::uniform_int_distribution<int> distribution(25,50);
			int ioCycles = distribution(generator);

			current->currentLeft=ioCycles;

			current->setState(process::state_t(WAIT));
			iodm->requestIO(current);

			if(calculate(cycles,iodm)==0){
				iodm->freeIO(current);
			}
		}
		else{
			calculate(cycles,iodm);
		}
	}
	if(inst.compare("YIELD")==0){
		current->setState(process::state_t(READY));
	}

	if(inst.compare("OUT")==0){
		cout << "Process Time Remaining: " << current->getTimeRemaining() << endl;
		cout << "Process Time Elapsed: " << current->getTimeElapsed() << endl;
		cout << "Process State: " << current->getState() << endl;
		cout << "I/O Requests Completed: " << current->ioComplete() << endl;
	}
	if(inst.compare("**CRITSTART**")==0){
		current->isCritical=true;
	}
	if(inst.compare("**CRITEND**")==0){
		current->isCritical=false;	
	}
	else{
		return -1;
	}
	return current->getTimeRemaining();
}
int processor::calculate(int cycles,io_device_mgr* iodm){
	int leftover = current->run(cycles);
	if(leftover>0){
		run(leftover,iodm);
	}
	return current->currentLeft;
}




process* processor::yield(process* _new){
	if(preempt){
		process* old = current;
		current=_new;
		old->setState(process::state_t(READY));
		current->setState(process::state_t(RUN));
		return old;
	}
	else{
		return NULL;
	}
}

bool processor::isInteruptable(){
	return preempt;
}
