#include "mem_mgmt.h"
#include "process_class.h"

#define SIZE 4096
using namespace std;

memory::memory(){
	bool mainmem[SIZE] = {};
	// set all values to false
	for(int i=0; i<SIZE; i++){
		mainmem[i] = 0;
	}
	int used = getMemory();
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

