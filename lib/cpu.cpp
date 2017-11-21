#include "../include/queue.h"
#include "../include/cpu.h"
#include "../include/system.h"
using namespace std;

processor::processor(){
	preeempt=true;

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
int processor::calculate(int cycles){
	current->run(cycles);
	if(current->isCritical()){
		preempt=false;
		return 1;
	}
	else{
		preempt=true;
		return current->getTimeRemaining();
	}
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
		return 1;
	}
}
process* processor::io(int cycles){
	current->setState(process::state_t(WAIT));
	//ask for new process
	system::blockInsert(&current);
	//system::readyRemove();
	return current;
}
int processor::out(string message){
	cout << message;
	return 0;
}
int processor::isInteruptable(){
	return preempt;
}
