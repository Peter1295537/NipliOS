#include "../include/mem_mgmt.h"
//#include "../include/process_class.h"
#define SIZE 4096
using namespace std;

memory::memory(){ //memory constructor
	bitset<SIZE> mem; 
	vector<process*> processes; //vector of pointers to processes
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

void memory::createProcess(string filename){
	process tmp(filename, pidCounter);
	int procmem = tmp.getMemory();
	if(procmem <= getFreeMemory()){ 
	processes.push_back(tmp); //adds tmp process to end of vector
	}
	else{
	cout<<"Insufficient memory"<<endl;
	}
}

int memory::findBlock(process p){ //first fit allocation
	int procmem = p.getMemory(); 
	if(mem.none()){ //if no bits are set, just allocate procmem amount of space
		allocate(0, procmem-1); 
	}
	else{ //find first contigous block big enough to hold process
		
	}
}
void memory::allocate(int base, int limit){ //set all bits from base register to limit register to 1
	for(int i = base; i <= limit; i++){
		mem.set(i, 1);
	}
}

void memory::free(int base, int limit){ //free bits from base to limit
	for(int i = base; i <= limit; i++){
		mem.set(i, 0);
	}
}
 
void memory::resetProcesses(){ //removes all processes
	mem.reset(); //set all bits to 0
	processes.clear();
}

int memory::getNumProcesses(){
	return processes.size();

}
