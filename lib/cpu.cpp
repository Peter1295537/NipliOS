#include "../include/queue.h"
#include "../include/cpu.h"
using namespace std;

processor::processor(){

}
int processor::load(process* _new){
	current = _new;
	current->setState(process::state_t(RUN));
	return 0;
	//return 1 if failure
}
int processor::calculate(int cycles){
	current->run(cycles);
	return current->getTimeRemaining();
}
process* processor::yield(process* _new){
	process* old = current;
	current=_new;
	old->setState(process::state_t(READY));
	current->setState(process::state_t(RUN));
	return old;
}
process* processor::io(int cycles){
	current->setState(process::state_t(WAIT));
	//ask for new process
	//need a queue for waiting processes, add to that
	//yield(
	return current;
}
int processor::out(string message){
	cout << message;
	return 0;
}
