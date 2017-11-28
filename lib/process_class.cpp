#include "../include/process_class.h"

using namespace std;
process::process(){
	state = state_t(NEW);
	pid=0;
	timeElapsed=0;
	hasResources=false;
	
}
process::process(string filename, int process_id){
	state = state_t(NEW);
	pid=process_id;
	timeElapsed=0;
	hasResources=false;

	
}
int process::getPID(){
	return pid;
}
int process::getTimeRemaining(){
	return timeRemaining;
}
 int process::getTimeElapsed(){
	return timeElapsed;
}
 int process::getMemory(){
	return memory;
}
 int process::getPriority(){
	return priority;
}
 int process::getRequests(){
	return numrequests;
}
 string process::getName(){
	return name;
}
process::state_t process::getState(){
	return state;
}

int process::calculate(int cycles){
	timeRemaining=cycles;
}

int process::run(int cycles){
	if(hasResources){
	
	}
	while(timeRemaining>0 && cycles>0){
		--timeRemaining;
		++timeElapsed;
		--cycles;
	}
		return timeRemaining;
}
int process::setState(state_t newstate){
	return state=newstate;
}
	
bool process::isCritical(){
	return (timeRemaining>=critsection_start && timeRemaining<=critsection_end);

}	
bool process::hasResources(){
	return hasResources;
}
