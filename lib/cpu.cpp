//#include "../include/queue.h"
#include "../include/cpu.h"
#include <cstdlib>
#include <ctime>

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
//	cout << current->getTimeRemaining() << endl;
	int x=cycles;
	string inst = current->nextInstruction();
	if(inst.compare(0,9,"CALCULATE")==0){
		if(current->currentLeft>0){
			calculate(cycles,iodm);
		}
		else{
			current->currentLeft=stoi(inst.substr(10));
			calculate(cycles,iodm);
		}
		return 0;
	}
	else if(inst.compare("IO")==0){
		if(!current->hasResources){
		srand(time(NULL));
		int ioCycles = rand() % 26 +25;
	
			current->request.clear();
			srand(time(NULL));
			current->request.push_back(rand() % 2 + 1);
			srand(time(NULL));
			current->request.push_back(rand() % 3 + 1);
			srand(time(NULL));
			current->request.push_back(rand() % 4 + 1);
			srand(time(NULL));
			current->request.push_back(rand() % 5 + 1);
			srand(time(NULL));
			current->request.push_back(rand() % 7 + 1);

//			cout << ioCycles << endl;
			current->currentLeft=ioCycles;
			current->setState(process::state_t(WAIT));
			iodm->requestIO(current);
			return 0;		
	
		}
		else{
			if(calculate(cycles,iodm)==0){
				iodm->freeIO(current);
				current->popInstruction();
			}
		}
		return 0;
	}
	else if(inst.compare("YIELD")==0){
		current->setState(process::state_t(READY));
		current->popInstruction();
		return 0;
	}
	else if(inst.compare("OUT")==0){
		cout << "Process Time Remaining: " << current->getTimeRemaining() << endl;
		cout << "Process Time Elapsed: " << current->getTimeElapsed() << endl;
		cout << "Process State: " << current->getState() << endl;
		cout << "I/O Requests Completed: " << current->ioComplete() << endl;
		current->popInstruction();
//		run(--cycles,iodm);
		return -1;

	}
	else if(inst.compare("**CRITSTART**")==0){
		current->isCritical=true;
		current->popInstruction();
//		run(cycles-1,iodm);
		return -1;
	}
	else if(inst.compare("**CRITEND**")==0){
		current->isCritical=false;	
		current->popInstruction();
//		run(cycles-1,iodm);
		return -1;
	}
	else {
		return -1;
	}
	cycles--;
	if (current->getTimeRemaining()==0)
		current->setState(process::state_t(EXIT));
	return current->getTimeRemaining();
}
int processor::calculate(int cycles,io_device_mgr* iodm){
	int leftover = current->run(cycles);
	if(leftover>0){
		if(current->getTimeRemaining()<=0){
			return 0;
		}
		else{
			run(leftover,iodm);
		}
	}
	return current->currentLeft;
}



/*

process* processor::yield(process* _new){
	if(preempt){
		process* old = current;
		current=_new;
		load(_new);
		cout<<current->getState();
		cout<<old->getState();
		old->setState(process::state_t(READY));
		return old;
	}
	else{
		return NULL;
	}
}
*/

bool processor::isInteruptable(){
	return preempt;
}
