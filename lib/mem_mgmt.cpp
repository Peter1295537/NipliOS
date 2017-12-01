#include "../include/mem_mgmt.h"
//#include "../include/process_class.h"
#define SIZE 4096
using namespace std;

memory::memory(){ //memory constructor
	bitset<SIZE> mem; 
	vector<process*> processes; //vector of processes
}
int memory::getTotalMemory(){
	return SIZE;
}
int memory::getFreeMemory(){ //returns amount of free memory
	return SIZE - getUsedMemory();
} 
int memory::getUsedMemory(){ //returns amount of memory used 
	return mem.count();
}

process* memory::getProcess(int pid){
	return &processes[pid];
}

void memory::createProcess(string filename, int x){
	process tmp(filename, x);
	int procmem = tmp.getMemory();
	if(procmem <= getFreeMemory()){ 
	processes.push_back(tmp); //adds tmp process to end of vector
	}
	else{
	cout<<"Insufficient memory"<<endl;
	}
} 
void memory::resetProcesses(){ //removes all processes
	mem.reset(); //set all bits to 0
	processes.clear();
}

int memory::getNumProcesses(){
	return processes.size();

}
