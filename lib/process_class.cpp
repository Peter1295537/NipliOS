#include "../include/process_class.h"

using namespace std;
process::process(){
	state = state_t(NEW);
	pid=0;
	timeElapsed=0;
	resources=false;
	
}
process::process(string filename, int process_id){
	state = state_t(NEW);
	pid=process_id;
	timeElapsed=0;
	timeRemaining=0;
	resources=false;
	ifstream ifs(filename);
	char data[32];
	char cmemory[32];
	ifs.getline(cmemory,32);
	memory = atoi(cmemory);
	while(ifs.good()){
		ifs.getline(data,32);
		string str(data);
		script.push_back(str);

		if(str.compare(0,9,"CALCULATE")==0){
			timeRemaining=timeRemaining + std::stoi(str.substr(10));
		}
		if(str.compare("IO")==0){
			numrequests++;
		}
	}
	ifs.close();

	
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


int process::run(int cycles){
	if(resources){
	
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
	return resources;
}
