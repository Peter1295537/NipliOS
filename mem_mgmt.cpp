#include "mem_mgmt.h"
#include "process_class.h"
#define SIZE 4096
using namespace std;

memory::memory(){ //memory constructor
	bool mainmem[SIZE] = {};
	// set all values to false
	for(int i=0; i<SIZE; i++){
		mainmem[i] = 0;
	}
	int used = getMemory();
	int pidCounter = 0;
	vector<process> processes[20]; //vector of processes
}
int memory::getTotalMemory(){
	return SIZE;
}
int memory::getFreeMemory(){ //returns amount of free memory
	return SIZE - used;
} 
int memory::getMemory(){ //returns amount of memory used 
	int space = 0;
	for(int i = 0; i < SIZE; i++){
		if(mainmem[i] == true){
		space++;
		}
	}
	return space;
}

process& memory::getProcess(int pid){
	return processes[pid];
}

void memory::createProcess(string filename){
	process tmp(filename, pidCounter); 
	processes.push_back(tmp); //adds tmp process to end of vector
	pidCounter++;
} 
void memory::resetProcesses(){ //removes all processes
	processes.clear();
	pidCounter = 0;
}
